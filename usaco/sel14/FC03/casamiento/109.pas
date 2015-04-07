type
  mat = array[1..10000,1..10000]of boolean;
  vec = array[0..100000]of boolean;
var
  i,m,n,x,y,cant,max : integer;
  m1 : mat;
  v : vec;
  arch,arch2 : text;
procedure dec(p:integer);
var
  g,f : integer;
begin
  if p = n then
   begin
     if cant > max then
       max := cant;
   end
  else
    for g := p + 1 to n do
      if not v[g] then
       begin
         cant := cant + 1;
         for f := 0 to n do
           if m1[g,f] then
             v[f] := TRUE;
         dec(g);
         cant := cant - 1;
         for f := 0 to n do
           if m1[g,f] then
             v[f] := FALSE;
       end; 
end;
begin
  assign(arch,'casamiento.in');
  assign(arch2,'casamiento.out');
  reset(arch);
  rewrite(arch2);
  readln(arch,n,m);
  for i := 1 to m do
   begin
     readln(arch,x,y);
     m1[x,y] := TRUE;
     m1[y,x] := TRUE;
   end;
  dec(-1);
  writeln(arch2,max);
  close(arch);
  close(arch2);
end.

