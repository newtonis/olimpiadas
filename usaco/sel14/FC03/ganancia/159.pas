type
  vec = array[1..50]of integer;
  vec2 = array[1..50]of boolean;
var
  i,a,d,sum,sum2,cant : integer;
  min : longint;
  v,v2 : vec;
  v3 : vec2;
  arch,arch2 : text;
procedure ga(p:integer);
var
  g,w,z: integer;
begin
  if p = a then
   begin
     if cant < min then
      begin
        min := cant;
      end;
   end
  else
    for g := 1 to a do
      if not v3[g] then
       begin
         z := sum2;
         w := cant;
         sum2 := sum2 - v[g];
         cant := cant + v2[g] * sum2;
         v3[g] := TRUE;
	     if cant > - 1 then
           ga(p+1);
         v3[g] := FALSE;
         cant := w;
         sum2 := z;
       end;
end;
begin
  sum := 0;
  min := 40 * 1000 * 25 * 51 + 1;
  assign(arch,'ganancia.in');
  assign(arch2,'ganancia.out');
  reset(arch);
  rewrite(arch2);
  readln(arch,a);
  for i := 1 to a do
   begin
     readln(arch,v2[i],v[i],d);
     sum := sum + d;
     sum2 := sum2 + v[i];
   end;
  ga(0);
  writeln(arch2,sum - min);
  close(arch);
  close(arch2);
end.
  
  
