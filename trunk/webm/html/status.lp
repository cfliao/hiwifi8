<table width="100%">
<tr>
	<td>
		<fieldset class="ui-widget-content">
			<legend>版本信息</legend>
			<table width="60%" cellspacing="10">
			<tr>
				<td width="33%">型号</td>
				<td>MSR1200</td>
			</tr>
			<tr>
				<td width="33%">软件版本</td>
				<td>3.11.0 Build 100325 Rel.32271n</td>
			</tr>
			</table>
		</fieldset>
	</td>
	</tr>
	<tr>
		<td colspan="2">
			<fieldset class="ui-widget-content">
				<legend>运行状态</legend>
				<table width="60%">
				<tr>
					<td width="33%">CPU使用率</td>
					<td><div id="cpubar"></div></td>
				</tr>
				<tr>
					<td width="33%">内存</td>
					<td><div id="membar"></div></td>
				</tr>
				<tr>
					<td width="33%">储存</td>
					<td><div id="flashbar"></div></td>
				</tr>
				<tr>
					<td width="33%">运行时间</td>
					<td><div id="uptime"></div></td>
				</tr>
				</table>
			</fieldset>
		</td>
	</tr>
	<tr>
		<td>
			<fieldset class="ui-widget-content">
				<legend>WAN接口信息</legend>
				<table width="70%">
				<tr>
					<td width="28%">WAN 接入类型</td>
					<td>PPPoE</td>
				</tr>
				<tr>
					<td>WAN MAC地址</td>
					<td>00:0C:29:E3:7F:FE</td>
				</tr>
				<tr>
					<td>WAN IP地址</td>
					<td>202.1.2.3/32</td>
				</tr>
				<tr>
					<td>流量</td>
					<td>RX: 2.86 MB (24425 Pkts.)&nbsp;&nbsp;TX:10.32 MB (27620 Pkts.)</td>
				</tr>
				</table>
			</fieldset>
		</td>
	</tr>
	<tr>
		<td>
			<fieldset class="ui-widget-content">
				<legend>LAN接口信息</legend>
				<table width="70%">
				<tr>
					<td width="28%">MAC地址</td>
					<td>00:0C:29:E3:7F:FE</td>
				</tr>
				<tr>
					<td>IP地址</td>
					<td>192.168.154.132/24</td>
				</tr>
				<tr>
					<td>流量</td>
					<td>RX: 2.86 MB (24425 Pkts.)&nbsp;&nbsp;TX:10.32 MB (27620 Pkts.)</td>
				</tr>
				</table>
			</fieldset>
		</td>
	</tr>
	<tr>
		<td>
			<fieldset class="ui-widget-content">
				<legend>无线WLAN信息</legend>
				<table width="70%">
				<tr>
					<td>MAC地址</td>
					<td>00:0C:29:E3:7F:FE</td>
				</tr>
				<tr>
					<td width="28%">状态</td>
					<td>工作中</td>
				</tr>
				<tr>
					<td>SSID(无线网络名)</td>
					<td>ArubaInstant</td>
				</tr>
				<tr>
					<td>无线频道</td>
					<td>Auto (Current channel 7)</td>
				</tr>
				<tr>
					<td>无线模式</td>
					<td>11bgn mixed(最大速率150Mbps)</td>
				</tr>
				<tr>
					<td>流量</td>
					<td>RX: 2.86 MB (24425 Pkts.)&nbsp;&nbsp;TX:10.32 MB (27620 Pkts.)</td>
				</tr>
				</table>
			</fieldset>
		</td>
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