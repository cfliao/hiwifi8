IsPost: @IsPost
<br/>
IsGet: @IsGet<br/>
<strong>hello, this is clp file</strong>
@{

	local IsPost = true
	print("This is multiple statement")
}

	<ul>
	@{ for k, v in pairs(Server) do}
		<li><strong>Server.@k</strong>:<label>@v</label></li>
	@{ end }
	</ul>

	<ul>
	@{ for k, v in pairs(Request) do}
		<li><strong>Request.@k</strong>:<label>@v</label></li>
	@{ end }
	</ul>

	<ul>
	</ul>
