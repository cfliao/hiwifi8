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
	$('#accordion').accordion({animated:'',autoHeight: false});
	$('input,select').addClass('text ui-widget-content ui-corner-all');
	$("button").button();
});
</script>
</head>
<body>

<table width="1002">
<tr class="ui-corner-top">
	<td colspan="2" style="text-align:right">
		<img src="/images/arubalogo.gif">
<!--		<img src="/images/logo.png" /> -->
	</td>
</tr>
<tr>
	<td colspan="2" style="text-align: right">
		admin &nbsp;
		<a href="/">Logout</a>
	</td>
</tr>
<tr>
	<td width="172" valign="top">
		<div class="ui-widget ui-widget-content ui-corner-top" style="margin: 0 auto">
			<div class="ui-dialog-titlebar ui-widget-header ui-helper-clearfix ui-dialog-titlebar-close ui-corner-top ui-dialog-title" style="text-align: center">Device Management Center</div>
			<div style="height: 515px;">
				<ul id="accordion">
				  <li>
					 <h3><a href="#status">Status</a></h3>
						<ul>
							<li><a href="/status.lp">Overview</a></li>
						</ul>
				  </li>
				  <li>
					 <h3><a href="#network">Network</a></h3>
						<ul>
							<li><a href="/lan.lp">LAN</a></li>
							<li><a href="/wan.lp">WAN</a></li>
						</ul>
				  </li>
				  <li>
					 <h3><a href="#wireless">Wireless</a></h3>
						<ul>
							<li><a href="/wlan.lp">Wireless Settings</a></li>
							<li><a href="/wlan_security.lp">Wireless Security</a></li>
							<li><a href="/wlan_mac.lp">Wireless MAC Filtering</a></li>
							<li><a href="/wlan_advanced.lp">Wireless Advanced</a></li>
							<li><a href="/wlan_stats.lp">Wireless Statistics</a></li>
						</ul>
				  </li>
				  <li>
					 <h3><a href="#">DHCP</a></h3>
						<ul>
							<li><a href="/dhcp.lp">DHCP Settings</a></li>
							<li><a href="/dhcp_client.lp">Clients List</a></li>
							<li><a href="/dhcp_reserv.lp">Address Reservation</a></li>
						</ul>
				  </li>
				  <li>
					 <h3><a href="#">Tools</a></h3>
						<ul>
							<li><a href="/time.lp">Time Settings</a></li>
							<li><a href="/diagnostic.lp">Diagnostic</a></li>
							<li><a href="/upgrade.lp">Firmware Upgrade</a></li>
							<li><a href="/factory.lp">Factory Defaults</a></li>
							<li><a href="/reboot.lp">Reboot</a></li>
							<li><a href="/password.lp">Password</a></li>
							<li><a href="/log.lp">System Log</a></li>
							<li><a href="/stats.lp">Statistics</a></li>
						</ul>
				  </li>
				  <li>
					 <h3><a href="#">Extend Center</a></h3>
						<ul>
							<li><a href="http://i.hiwifi.net/">ArubaInstant</a></li>
						</ul>
				  </li>
				</ul>
			</div>
		</div>
	</td>

	<td  valign="top">
		<div class="ui-widget ui-widget-content ui-corner-top" style="height: 540px;">
		<div class="ui-widget-header ui-helper-clearfix ui-corner-top" style="text-align: center;">&nbsp;</div>
@{RenderBody()}
		</div>
	</td>
</tr>
<tr>
	<td colspan="2"><hr><div style="text-align:right">&copyAruba Networks&nbsp;</div></td>
</tr>
</table>
</body>
</html>