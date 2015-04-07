program ganancia;
type
  v=array [1..50] of integer;
  v2=array[1..50] of boolean;
var
  recauda,tartot,perdidam,autos,precio,cont,pase:longint;
  textin,textout:text;
  tarifa,tiempo:v;
  arreglo:v2;
  
procedure taller(perdida:longint);   //PROCEDIMIENTO  
var
  contp:integer;
begin
  contp:=0;
  repeat
    contp:=contp+1;
    if not arreglo[contp] then
      begin
        tartot:=tartot-tarifa[contp];
        arreglo[contp]:=true;
        pase:=pase+1;
        
        if pase<autos then
          taller(perdida+tartot*tiempo[contp])
        else
          if perdida+tartot*tiempo[contp]<perdidam then
            perdidam:=perdida+tartot*tiempo[contp];  
        
        pase:=pase-1;      
        arreglo[contp]:=false;
        tartot:=tartot+tarifa[contp];
      end;  
  until contp=autos;
end;

begin
  assign(textin,'ganancia.in');  //INICIAR ARCHIVO
  assign(textout,'ganancia.out');
  reset(textin);
  rewrite(textout);
  
  recauda:=0;  //INICIALIZACION
  tartot:=0;
  pase:=0;
  perdidam:=51000000;
  
  for cont:=1 to 50 do
    arreglo[cont]:=false;
  
  readln(textin,autos);
  for cont:=1 to autos do
    begin
      readln(textin,tiempo[cont],tarifa[cont],precio);
      recauda:=recauda+precio;
      tartot:=tartot+tarifa[cont];
    end;
  
  taller(0);
  writeln(textout,recauda-perdidam);
  
  close(textin);
  close(textout);
end.
