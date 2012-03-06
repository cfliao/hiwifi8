<table width="50%" border="0"  style="margin: 10px">
	<tr><td colspan="2">&nbsp;</td></tr>
	<tr>
		<td colspan="2"><span id="validateTips" /></td>
	</tr>
	<tr>
		<td><label for="name">File</label></td>
		<td>
			<input type="file">
		</td>
	</tr>
	<tr>
		<td><label for="password">Firmware Version</label></td>
		<td>3.11.0 Build 100325 Rel.32271n</td>
	</tr>
	<tr>
		<td><label for="password">Hardware Version</label></td>
		<td>WR741N v1/v2 00000000</td>
	</tr>
	<tr>
		<td>&nbsp;</td>
		<td><button id="save-btn">Upload</button></td>
	</tr>
	<tr>
		<td colspan="2">&nbsp;</td>
	</tr>
	<tr>
		<td><label for="password">&nbsp;</label></td>
		<td><div id="uploadbar" /></td>
	</tr>
	<tr>
		<td colspan="2">&nbsp;</td>
	</tr>
	<tr>
		<td><label for="password">Uploaded Version</label></td>
		<td>4.11.0 Build 100325 Rel.32271n</td>
	</tr>
	<tr>
		<td>&nbsp;</td>
		<td><button id="save-btn">Upgrade</button></td>
	</tr>
	<tr>
		<td colspan="2"><hr/></td>
	</tr>


</table>
<script type="text/javascript">
$(function(){
	$('#uploadbar').progressbar({value: 30});
});
</script>