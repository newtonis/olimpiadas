program caballo;
type
  m=array [1..1000,1..1000] of char;
  v3=array[1..300000] of integer;
  v2=array[1..8] of integer;
  v4=array[1..7] of char;
var
  textin,textout:text;
  total,cont,cont2,fila,col,modu:longint;
  tab:m;
  cab:v4;
  salhor,salver:v2;
procedure saltar(cf,cc:integer);
var
  cant,cont8,ind:longint;
  orden,x,y:v3;
begin
  cant:=1;
  ind:=1;
  orden[1]:=1;
  x[1]:=cf;
  y[1]:=cc;
  repeat
   for cont8:=1 to 8 do
       if cab[orden[ind]+1]=tab[x[ind]+salhor[cont8],y[ind]+salver[cont8]]then
            begin
              cant:=cant+1;
              x[cant]:=x[ind]+salhor[cont8];
              y[cant]:=y[ind]+salver[cont8];
              orden[cant]:=orden[ind]+1;
              if orden[cant]=7 then
                total:=total+1;
            end;
       
     
   ind:=ind+1;    
   until ind>cant;
end;  
begin
  assign(textin,'caballos.in');
  assign(textout,'caballos.out');
  reset(textin);
  rewrite(textout);
  
  salhor[1]:=1;
  salhor[2]:=1;
  salhor[3]:=2;
  salhor[4]:=2;
  salhor[5]:=-1;
  salhor[6]:=-1;
  salhor[7]:=-2;
  salhor[8]:=-2;
  total:=0;
  salver[1]:=2;
  salver[2]:=-2;
  salver[3]:=1;
  salver[4]:=-1;
  salver[5]:=2;
  salver[6]:=-2;
  salver[7]:=1;
  salver[8]:=-1;
  cab[1]:='C';
  cab[2]:='A';
  cab[3]:='B';
  cab[4]:='A';
  cab[5]:='L';
  cab[6]:='L';
  cab[7]:='O';
  
  for cont:=1 to 1000 do
    for cont2:=1 to 1000 do
      tab[cont,cont2]:='W';
  readln(textin,fila,col,modu);
  for cont:=1 to fila do
    begin
      for cont2:=1 to col do
        read(textin,tab[cont,cont2]); 
      readln(textin);        
    end;
  for cont:=1 to fila do
    for cont2:=1 to col do
      if tab[cont,cont2]='C' then
         saltar(cont,cont2);
  writeln(textout,total mod modu);       
  close(textin);
  close(textout);
end.
