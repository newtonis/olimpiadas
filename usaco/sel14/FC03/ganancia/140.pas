type
  vec = array[1..50]of integer;
var
  i,a,d,sum,sum2,cant : integer;
  min : longint;
  v,v2 : vec;
  arch,arch2 : text;
procedure ga(p:integer);
var
  g : integer;
begin
  if p = a then
   begin
     if cant < min then
       min := cant;
   end
  else
    for g := p + 1 to a do
      begin
        sum2 := sum2 - v[g];
        cant := cant + v2[g] * sum2;
        ga(g);
        cant := cant - v2[g] * sum2;
        sum2 := sum2 + v[g];
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
  writeln(arch2,sum - min-1);
  close(arch);
  close(arch2);
end.
  
  
