<?php

function system_get_language_code() {
	global $config;
	$code = "en-US"; // Set default code.

	// a language code, as per [RFC3066]
	if (isset($config['system']['language'])) {
		$language = $config['system']['language'];
		$code = str_replace("_", "-", $language);
	}

	return $code;
}


$g['theme'] = get_current_theme();

$pagetitle = gentitle( $pgtitle );

?><!doctype html>
<!--[if IE 8 ]><html lang="<?=system_get_language_code();?>" class="ie ie8 lte9 lte8 no-js"><![endif]-->
<!--[if IE 9 ]><html lang="<?=system_get_language_code();?>" class="ie ie9 lte9 no-js"><![endif]-->
<!--[if (gt IE 9)|!(IE)]><!--><html lang="<?=system_get_language_code();?>" class="no-js"><!--<![endif]-->
	<head>

		<meta charset="UTF-8" />
		<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">

		<meta name="robots" content="index, follow, noodp, noydir" />
		<meta name="keywords" content="" />
		<meta name="description" content="" />
		<meta name="copyright" content="" />
		<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no" />

		<title><?php echo($config['system']['hostname'] . "." . $config['system']['domain'] . " - " . $pagetitle); ?></title>

		<!-- include (theme) style -->
		<link href="/ui/themes/<?=$g['theme'];?>/build/css/main.css" media="screen, projection" rel="stylesheet">

		<!-- TODO: move to theme style -->
		<style>
			.menu-level-3-item {
				font-size: 90%;
				padding-left: 54px !important;
			}
		</style>

		<!-- Favicon -->
		<link href="/ui/themes/<?=$g['theme'];?>/build/images/favicon.png" rel="shortcut icon">

		<!-- Stylesheet for fancy select/dropdown -->
		<link rel="stylesheet" type="text/css" href="/ui/themes/<?=$g['theme'];?>/build/css/bootstrap-select.css">

		<!-- bootstrap dialog -->
		<link href="/ui/themes/<?=$g['theme'];?>/build/css/bootstrap-dialog.css" rel="stylesheet" type="text/css" />


		<!-- Font awesome -->
		<link rel="stylesheet" href="/ui/css/font-awesome.min.css">

		<!--[if lt IE 9]><script src="//cdnjs.cloudflare.com/ajax/libs/html5shiv/3.7.2/html5shiv.min.js"></script><![endif]-->

		<!-- nvd3 -->
		<link rel="stylesheet" href="/ui/css/nv.d3.css">

		<script>var theme = '<?=$g['theme'];?>'; </script>

		<!-- JQuery -->
		<script type="text/javascript" src="/ui/js/jquery-1.11.2.min.js"></script>

		<!-- Ticker used for notices-->
		<script type="text/javascript" src="/javascript/ticker.js"></script>

		<!-- d3 -->
		<script type="text/javascript" src="/ui/js/d3.min.js"></script>

		<!-- nvd3 -->
		<script type="text/javascript" src="/ui/js/nv.d3.min.js"></script>

		<?php
		/*
		 *	Find all javascript files that need to be included
		 *	for this page ... from the arrays ... :)
		 *	Coded by: Erik Kristensen
		 */

		$dir  = trim(basename($_SERVER['SCRIPT_FILENAME'], '.php'));
		$path = '/usr/local/www/javascript/' . $dir . '/';
		if (is_dir($path)) {
			if ($dh = opendir($path)) {
				while (($file = readdir($dh)) !== false) {
					if (is_dir($file))
						continue;
					echo "\t<script type=\"text/javascript\" src=\"/javascript/{$dir}/{$file}\"></script>\n";
				}
				closedir($dh);
			}
		}

		?>

		<?php if (basename($_SERVER["SCRIPT_FILENAME"] != "index.php")): ?>
		<script type="text/javascript">
		//<![CDATA[
		$( document ).ready(function() {
			$('[data-toggle="tooltip"]').tooltip();
			$("input").attr("autocomplete","off");
			// hide empty menu items
			$('#mainmenu > div > .collapse').each(function(){
				// cleanup empty second level menu containers
				$(this).find("div.collapse").each(function(){
					if ($(this).children().length == 0 ) {
							$("#mainmenu").find('[href="#'+$(this).attr('id')+'"]').remove();
							$(this).remove();
					}
				});

				// cleanup empty first level menu items
				if ($(this).children().length == 0) {
					$("#mainmenu").find('[href="#'+$(this).attr('id')+'"]').remove();
				}
			});

			// link showhelp class behavior
			$("a[class='showhelp']").click(function (event) {
				$("*[for='" + $(this).attr('id') + "']").toggleClass("hidden show");
				event.preventDefault();
			});

			// handle all help messages show/hide
			$('[id*="show_all_help"]').click(function(event) {
				$('[id*="show_all_help"]').toggleClass("fa-toggle-on fa-toggle-off");
				$('[id*="show_all_help"]').toggleClass("text-success text-danger");
				if ($('[id*="show_all_help"]').hasClass("fa-toggle-on")) {
					$('[for*="help_for"]').addClass("show");
					$('[for*="help_for"]').removeClass("hidden");
				} else {
					$('[for*="help_for"]').addClass("hidden");
					$('[for*="help_for"]').removeClass("show");
				}
				event.preventDefault();
			});

		});
		//]]>
		</script>

		<? endif; ?>


<?php if (!isset($closehead) || !$closehead):?></head><? endif;?>
