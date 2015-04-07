type
  mat = array[-1..1000,-1..1000]of char;
  mat2 = array[-1..1000,-1..1000]of boolean;
  vec = array[1..8]of integer;
var
  f,c,mo,cant,i,e : integer;
  c1 : string;
  v,v2 : vec;
  m : mat;
  m2 : mat2;
  arch,arch2 : text;
procedure ca(id,x,y,an,an1:integer);
var
  g : integer;
begin
  if id = 7 then
    cant := cant + 1
  else
   begin
    for g := 1 to 8 do
     begin
      if (m[x+v[g],y+v2[g]] = c1[id+1]) and (x+v[g] <> an) and (y+v2[g] <> an1) then
       begin
         ca(id+1,x+v[g],y+v2[g],x,y);
       end;  
     end;
   end; 
end;   
begin
  assign(arch,'caballos.in');
  assign(arch2,'caballos.out');
  c1 := 'CABALLO';
  reset(arch);
  rewrite(arch2);
  readln(arch,f,c,mo);
  cant := 0;
  for i := 1 to f do
   begin   
     for e := 1 to c do
       read(arch,m[i,e]);
     readln(arch);
   end;
  v[1] := 1;
  v2[1] := 2;
  v[2] := -1;
  v2[2] := -2;
  v[3] := -1;
  v2[3] := 2;
  v[4] := 1;
  v2[4] := -2;
  v2[5] := 1;
  v[5] := 2;
  v2[6] := -1;
  v[6] := -2;
  v2[7] := -1;
  v[7] := 2;
  v2[8] := 1;
  v[8] := -2;
  for i := 1 to f do
   for e := 1 to c do
     if (m[i,e] = 'C') then
      begin
        m2[i,e] := TRUE;
        ca(1,i,e,-1,-1);
        if cant >= mo then
          cant := cant mod mo;
      end;
  writeln(arch2,cant);
  close(arch);
  close(arch2);
end.
  
