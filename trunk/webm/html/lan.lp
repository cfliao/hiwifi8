<!--#include virtual="layout/top.shtml" -->
<form action="" method="post" id='lan_form'>
<table width="50%" border="0"  style="margin: 10px">
	<tr><td colspan="2">&nbsp;</td></tr>
	<tr>
		<td colspan="2"><span id="validateTips" /></td>
	</tr>
	<tr>
		<td><label for="mac">MAC Address</label></td>
		<td><span id='mac'>94-0C-6D-4B-99-2E</span></td>
	</tr>
	<tr>
		<td><label for="ipaddr">IP Address</label></td>
		<td><input type="text" name='ipaddr'/></td>
	</tr>
	<tr>
		<td><label for="netmask">Subnet Mask</label></td>
		<td><input type="text" name='netmask'/></td>
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
	$.ajax({
		url:"/config.xml",
		success:function(xml){
			$(xml).find("configuration>network>interface>lan").each(function(){
				var lan = $(this);
				var ifname = lan.find('ifname').text();
				var proto  = lan.find('proto').text();
				var ipaddr = lan.find('ipaddr').text();
				var netmask= lan.find('netmask').text();
				var gateway= lan.find('gateway').text();
				var dns	   = lan.find('dns').text();

				$('#lan_form input[name="ipaddr"]').val(ipaddr);
				$('#lan_form input[name="netmask"]').val(netmask);
			});
        }
    });
});

/* http://www.51240.com/jsmin/ */
//$(function(){var lan_cfg=null;$.ajax({url:"/config.xml",success:function(xml){$(xml).find("configuration>network>interface>lan").each(function(){var lan=$(this);var ifname=lan.find('ifname').text();var proto=lan.find('proto').text();var ipaddr=lan.find('ipaddr').text();var netmask=lan.find('netmask').text();var gateway=lan.find('gateway').text();var dns=lan.find('dns').text();$('#lan_form input[name="ipaddr"]').val(ipaddr);$('#lan_form input[name="netmask"]').val(netmask);});}});});
</script>
<!--#include virtual="layout/bottom.shtml" -->