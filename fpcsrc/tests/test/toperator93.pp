{ %NORUN }

program toperator93;

{$mode delphi}

type
  TString80 = String[80];
  TString90 = String[90];
  TString40 = String[40];
  TString100 = String[100];

  TTest = record
    class operator Implicit(const aArg: TTest): TString80;
  end;

class operator TTest.Implicit(const aArg: TTest): TString80;
begin

end;

var
  t: TTest;
  s: TString80;
begin
  s := t;
end.
