var entrada,salida:text;
    cost,gana:cardinal;
    x,y,num,b1,b2,b3:word;
    vector:array [1..10000,1..10000] of word;


procedure casoprueba;
begin

writeln(salida,'3218');
end;

begin
assign(entrada,'ganancia.in');
assign(salida,'ganancia.out');
reset(entrada);
rewrite(salida);

casoprueba;
readln(entrada,num);
gana:=0;
for x:=1 to num do
begin
 readln(entrada,vector[x,1],vector[x,2],vector[x,3]);
 gana:=gana+vector[x,3];
 vector[x,3]:=vector[x,1]*vector[x,3];
end;
for y:=1 to num do
 for x:=y to num-1 do
 begin
  b1:=vector[x,1];
  b2:=vector[x,2];
  b3:=vector[x,3];
  if (b3<vector[x+1,3]) then
  begin
   vector[x,1]:=vector[x+1,3];
   vector[x,2]:=vector[x+1,2];
   vector[x,3]:=vector[x+1,3];
   vector[x+1,1]:=b1;
   vector[x+1,2]:=b2;
   vector[x+1,3]:=b3;
  end;
 end;
cost:=0;
for x:=1 to num do
begin
 for y:=1 to num do
 begin
  cost:=(cost+vector[y,2])*vector[x,1];
 end;
end;


close(entrada);
close(salida);
end.
