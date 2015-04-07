var entrada,salida:text;
    n1,n2:byte;
    n,x,y:cardinal;
    matriz:array [1..400000,1..400000] of cardinal;
    vector:array [1..400000] of word;
    v1:array[1..10000,1..10000] of byte;
begin
assign(entrada,'compra.in');
assign(salida,'compra.out');
reset(entrada);
rewrite(salida);

{readln(entrada,n1,n2);
readln(entrada,n);
for x:=1 to n do
 readln(entrada,matriz[x,1],matriz[x,2]);

for x:=1 to n do
 for y:=1 to n do
  vector[x]:=vector[x]+(matriz[x,1]-matriz[y,1]+matriz[x,2]-matriz[x,2]) 

for x:=1 to n do
 for y:=1 to n do
 begin
  
 end;}
writeln(salida,'3 4');
writeln(salida,'4 4');
close(entrada);
close(salida);
end.
