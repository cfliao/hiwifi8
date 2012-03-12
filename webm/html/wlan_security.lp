<form action="index.lp" method="post">
<table width="70%" border="0"  style="margin: 10px">
	<tr><td colspan="2">&nbsp;</td></tr>
	<tr>
		<td colspan="2"><span id="validateTips" /></td>
	</tr>
	<tr>
		<td><label for="name">安全类型</label></td>
		<td>
			<input type="radio" id="enc_none" name="encryption" value="none" checked /><label for="enc_none">不开启无线安全</label>
			<input type="radio" id="enc_psk2" name="encryption" value="psk2"  /><label for="enc_psk2">WPA-PSK/WPA2-PSK</label>
			<input type="radio" id="enc_wpa2" name="encryption" value="wpa2"  /><label for="enc_wpa2">WPA/WPA2</label>
			<input type="radio" id="enc_wep" name="encryption" value="wep"  /><label for="enc_wep">WEP</label>
		</td>
	</tr>
	<tr>
		<td><label for="password">认证类型</label></td>
		<td>
			<select>
				<option>自动</option>
				<option>WPA-PSK</option>
				<option>WPA2-PSK</option>
			</select>
		</td>
	</tr>
	<tr>
		<td><label for="password">加密算法</label></td>
		<td>
			<select>
				<option>自动</option>
				<option>TKIP</option>
				<option>AES</option>
			</select>
		</td>
	</tr>
	<tr>
		<td><label for="password">PSK密码</label></td>
		<td><input type="text"/></td>
	</tr>
	<tr>
		<td><label for="password">组密钥更新周期</label></td>
		<td><input type="text" style="width:50px" />（单位为秒，最小值为30，不更新则为0）</td>
	</tr>
	<tr>
		<td colspan="2">&nbsp;</td>
	</tr>
	<tr>
		<td><label for="password">认证类型</label></td>
		<td>
			<select>
				<option>自动</option>
				<option>WPA</option>
				<option>WPA2</option>
			</select>
		</td>
	</tr>
	<tr>
		<td><label for="password">加密算法</label></td>
		<td>
			<select>
				<option>自动</option>
				<option>TKIP</option>
				<option>AES</option>
			</select>
		</td>
	</tr>
	<tr>
		<td><label for="password">Radius服务器IP</label></td>
		<td><input type="text"/></td>
	</tr>
	<tr>
		<td><label for="password">Radius端口</label></td>
		<td><input type="text" value="1812" style="width:50px" />（单位为秒，最小值为30，不更新则为0）</td>
	</tr>
	<tr>
		<td><label for="password">Radius密码</label></td>
		<td><input type="text"/></td>
	</tr>
	<tr>
		<td><label for="password">组密钥更新周期</label></td>
		<td><input type="text" style="width:50px" />（单位为秒，最小值为30，不更新则为0）</td>
	</tr>
	<tr>
		<td colspan="2">&nbsp;</td>
	</tr>
	<tr>
		<td><label for="password">认证类型</label></td>
		<td>
			<select>
				<option>自动</option>
				<option>开放系统</option>
				<option>共享密钥</option>
			</select>
		</td>
	</tr>
	<tr>
		<td><label for="password">认证类型</label></td>
		<td>
			<select>
				<option>十六进制</option>
				<option>ASCII码</option>
			</select>
		</td>
	</tr>
	<tr>
		<td><label for="password">密钥1</label></td>
		<td><input type="text">
		</td>
	</tr>
	<tr>
		<td><label for="password">密钥2</label></td>
		<td><input type="text">
		</td>
	</tr>
	<tr>
		<td><label for="password">密钥3</label></td>
		<td><input type="text">
		</td>
	</tr>
	<tr>
		<td><label for="password">密钥4</label></td>
		<td><input type="text">
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

});
</script>