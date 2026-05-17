program relpath;
uses
  SysUtils;

var
	BaseDir: string;
	TargetDir: string;
begin
	TargetDir := ParamStr(1);
	BaseDir := ParamStr(2);
	if BaseDir = ''
	then begin
		BaseDir := GetCurrentDir;
	end;
	WriteLn(ExtractRelativePath(IncludeTrailingPathDelimiter(BaseDir), TargetDir));
end.
