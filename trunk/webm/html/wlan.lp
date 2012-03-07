<form action="index.lp" method="post" id="wlan_form">
<table width="50%" border="0"  style="margin: 10px">
	<tr><td colspan="2">&nbsp;</td></tr>
	<tr>
		<td colspan="2"><span id="validateTips" /></td>
	</tr>
	<tr>
		<td><label for="name">WLAN</label></td>
		<td>
			<div id="wlan_status_p">
				<input type="radio" id="wstatus1" name="wlan_status" value="1" checked /><label for="wstatus1">Enable</label>
				<input type="radio" id="wstatus2" name="wlan_status" value="2" /><label for="wstatus2">Disable</label>
			</div>
		</td>
	</tr>
	<tr>
		<td><label for="name">SSID</label></td>
		<td><input type="text" name="ssid" id="ssid"/></td>
	</tr>
	<tr>
		<td><label for="name">Channel</label></td>
		<td>
			<select name="channel" id="channel">
				<option value="auto">Auto</option>
				<option value="1">1</option>
				<option value="2">2</option>
				<option value="3">3</option>
				<option value="4">4</option>
				<option value="5">5</option>
				<option value="6">6</option>
				<option value="7">7</option>
				<option value="8">8</option>
				<option value="9">9</option>
				<option value="10">10</option>
				<option value="11">11</option>
			</select>
		</td>
	</tr>
	<tr>
		<td><label for="name">Mode</label></td>
		<td>
			<select>
				<option>11b only</option>
				<option>11g only</option>
				<option>11bg mixed</option>
				<option>11bgn mixed</option>
			</select>
		</td>
	</tr>
	<tr>
		<td><label for="name">频段带宽</label></td>
		<td>
			<select>
				<option>Automatic</option>
				<option>20MHz</option>
				<option>40Mhz</option>
			</select>
		</td>
	</tr>
	<tr>
		<td><label for="name">SSID Broadcast</label></td>
		<td>
			<div id="wlan_brdcast_p">
				<input type="radio" id="wbrdcast1" name="wlan_brdcast" value="1" checked /><label for="wbrdcast1">Enable</label>
				<input type="radio" id="wbrdcast2" name="wlan_brdcast" value="2" /><label for="wbrdcast2">Disable</label>
			</div>
		</td>
	</tr>
	<tr>
		<td colspan="2"><hr/></td>
	</tr>
	<tr>
		<td>&nbsp;</td>
		<td><button id="save-btn">Save</button></td>
	</tr>
	<tr>
		<td colspan="2">&nbsp;</td>
	</tr>
</table>
</form>
<script type="text/javascript">
$(function(){
	$('#wlan_status_p').buttonset();
	$('#wlan_brdcast_p').buttonset();

	$.ajax({
		url:"/config.xml",
		success:function(xml){
			$(xml).find("configuration>wireless").each(function(){
				var wlan = $(this);
				
				wlan.find('wifi-device').each(function() {
					var channel = $(this).find('channel').text();
					$('#channel option[value="' + channel + '"]').attr("selected", true);
				});
				
				wlan.find('wifi-iface').each(function() {
					$('#ssid').val(wlan.find('ssid').text());
				});
			});
        }
    });	
});
</script>