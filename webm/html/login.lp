<!DOCTYPE html>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<title>Device Management Center</title>
	<link type="text/css" href="/css/all.css" rel="stylesheet" />
	<link type="text/css" href="/css/sunny/jquery-ui-1.8.17.custom.css" rel="stylesheet" />
	<script type="text/javascript" src="/js/jquery.min.js"></script>
	<script type="text/javascript" src="/js/jquery-ui.min.js"></script>
	<script type="text/javascript">
		$(function(){
			var name = $( "#user" );
			var password = $( "#password" );
			var tips = $("#validateTips");

			$('form input').addClass('text ui-widget-content ui-corner-all');
			$("button").button();


			$('#login_form').submit(function() {
				var bValid = true;

				bValid = bValid && checkLength(name,"username",3,16);
				bValid = bValid && checkRegexp( name, /^[a-z]([0-9a-z_])+$/i, "Username may consist of a-z, 0-9, underscores, begin with a letter." );

				bValid = bValid && checkLength(password,"password",3,16);
				bValid = bValid && checkRegexp( password, /^([0-9a-zA-Z])+$/, "Password field only allow : a-z 0-9" );

				if (bValid == false) {updateTips('username or password wrong'); return false};
			});

			function checkLength( o, n, min, max ) {
				if ( o.val().length > max || o.val().length < min ) {
					o.addClass( "ui-state-error" );
					updateTips( "Length of " + n + " must be between " +
						min + " and " + max + "." );
					return false;
				} else {
					return true;
				}
			}
			function checkRegexp( o, regexp, n ) {
				if ( !( regexp.test( o.val() ) ) ) {
					o.addClass( "ui-state-error" );
					updateTips( n );
					return false;
				} else {
					return true;
				}
			}

			function updateTips(t) {
				tips.text(t).effect("highlight",{},1500);
			}

		});
	</script>
	<style type="text/css">
		/*demo page css*/
		body{ font: 75.5% "Trebuchet MS", sans-serif; margin: 50px;}
	</style>
</head>
<body>
	<div class="ui-widget ui-widget-content ui-corner-all" style="width:350px;margin: 0 auto">
		<div class="ui-dialog-titlebar ui-widget-header ui-helper-clearfix ui-dialog-titlebar-close ui-corner-top ui-dialog-title" style="text-align: center">Device Management Center</div>
		<div>
			<form action="/authorize" id="login_form">
				<table width="50%" border="0"  style="margin: 0 auto">
					<tr><td colspan="2">&nbsp;</td></tr>
					<tr>
						<td colspan="2"><span id="validateTips" /></td>
					</tr>
					<tr>
						<td><label for="name">Name</label></td>
						<td><input type="text" name="user" id="user"/></td>
					</tr>
					<tr>
						<td><label for="password">Password</label></td>
						<td><input type="password" name="password" id="password"/></td>
					</tr>
					<tr>
						<td>&nbsp;</td>
						<td><button id="login-btn">Login</button></td>
					</tr>
					<tr>
						<td colspan="2" style="text-align:center">demo user: admin admin</td>
					</tr>
					<tr>
						<td colspan="2">&nbsp;</td>
					</tr>
				</table>
			</form>
		</div>
	</div>
</body>
</html>