<table width="70%" border="0"  style="margin: 10px">
	<tr><td colspan="2">&nbsp;</td></tr>
	<tr>
		<td colspan="2"><span id="validateTips" /></td>
	</tr>
	<tr>
		<td width="20%"><label for="name">&nbsp;</label></td>
		<td>
			Click the following button to reset all configuration settings to their default values.
		</td>
	</tr>
	<tr>
		<td><label for="password">&nbsp;</label></td>
		<td><button id="save-btn">Restore</button></td>
	</tr>
	<tr>
		<td colspan="2">&nbsp;</td>
	</tr>
	<tr>
		<td><label for="password">&nbsp;</label></td>
		<td><div id="restorebar"/></td>
	</tr>
	<tr>
		<td colspan="2">&nbsp;</td>
	</tr>
	<tr>
		<td><label for="password">&nbsp;</label></td>
		<td>Restore Ok, to <a href="status.html">Status</a> Page</td>
	</tr>
</table>
<script type="text/javascript">
$(function(){
	$('#restorebar').progressbar({value: 30});
});
</script>