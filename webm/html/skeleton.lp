<table width="100%">
<tr>
	<td>
		<fieldset class="ui-widget-content">
			<legend>设备信息</legend>
			<table width="60%" cellspacing="10">
			<tr>
				<td width="33%">型号</td>
				<td>MSR1200</td>
			</tr>
			<tr>
				<td width="33%">序列号</td>
				<td>61A12092800027</td>
			</tr>
			<tr>
				<td width="33%">MAC地址</td>
				<td>00:17:7b:2a:66:c0</td>
			</tr>
			</table>
		</fieldset>
	</td>
	</tr>
	<tr>
		<td colspan="2">&nbsp;</td>
	</tr>
	<tr>
		<td>&nbsp;</td>
	</tr>
</table>
<script type="text/javascript">
$(function(){
	$("#cpubar").progressbar({
		height: 20,
		value: 20
	}).css({height: '15px'});
	$("#membar").progressbar({
		value: 60
	}).css({height: '15px'});
	$("#flashbar").progressbar({
		value: 20,
		showText: true
	}).css({height: '15px'});

	$('#uptime').html("1小时20分钟32秒");
});
</script>