var entrada,salida:text;
    x,y,cont,pmax,num:cardinal;
    vector:array[1..10000,1..3] of cardinal;
    matriz:array[1..10000,1..10000] of byte;
    n:byte;
procedure probar;
begin
 for x:=1 to num do
  writeln(salida,vector[x,1],' ',vector[x,2]);
 for y:=1 to pmax do
 begin
  for x:=1 to pmax do
   write(salida,matriz[y,x],' ');
  writeln(salida);
 end;

end;


{main}
begin
assign(entrada,'casamiento.in');
assign(salida,'casamiento.out');
reset(entrada);
rewrite(salida);

readln(entrada,pmax,num);
for x:=1 to num do
begin
 readln(entrada,vector[x,1],vector[x,2]);
 matriz[vector[x,1],vector[x,2]]:=1;
 matriz[vector[x,2],vector[x,1]]:=1; 
end;

for y:=1 to pmax do
begin
 n:=0;
 for x:=1 to pmax do
  n:=n+matriz[y,x];
 matriz[y,y]:=n;
end;
cont:=0;
for n:=1 to num do
begin
 if ((matriz[vector[n,1],vector[n,1]]=1) or (matriz[vector[n,2],vector[n,2]]=1)) then inc(cont);
 if ((matriz[vector[n,1],vector[n,1]]=2) and (matriz[vector[n,2],vector[n,2]]=2))then 
 begin
  y:=0;
  for x:=1 to pmax do
   if ((matriz[vector[n,1],x]=1) and (matriz[x,x]=2)) then inc(y); 
  if (y=2) then inc(cont);
 end;
end;

{probar;}
writeln(salida,cont);

close(entrada);
close(salida);
end.
