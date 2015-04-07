program compra;
type
  vec=array [1..400000] of integer;
  mov=array[1..8] of integer;
  m=array[1..100000,1..100000] of integer;
var
  v,h,c,cont,x,y,cm,maxd,minn,minr,sec,cont2:longint;
  textin,textout:text;
  cv,ch,maxc,mindx,mindy:vec;
  visita,dist:m;
  xy,xmy,mxmy,mxy,aumenta:boolean;
begin
assign(textin,'compra.in');
assign(textout,'compra.out');
reset(textin);
rewrite(textout);
x:=0; minr:=1000000;
y:=0;
readln(textin,v,h);
readln(textin,c);
for cont:=1 to c do
  readln(textin,cv[cont],ch[cont]);
repeat
  maxd:=0;
  sec:=0;
  for cont:=1 to  c do
     if abs(cv[cont]-y)+abs(ch[cont]-x)>maxd then
       begin
         maxd:=abs(cv[cont]-y)+abs(ch[cont]-x);
         maxc[1]:=cont;
         cm:=1;
       end
     else if  abs(cv[cont]-y)+abs(ch[cont]-x)=maxd then
       begin
         cm:=cm+1;
         maxc[cm]:=cont;
       end;
   dist[x,y]:=maxd;
   if maxd<minr then minr:=maxd;
   visita[x,y]:=1;
   for cont:=1 to cm do
     if (cv[maxc[cont]]>y) and (ch[maxc[cont]]>x) then
       begin xy:=true; sec:=sec+1; end
     else if (cv[maxc[cont]]<y) and (ch[maxc[cont]]<x) then
       begin mxmy:=true; sec:= sec+1; end
     else if (cv[maxc[cont]]>y) and (ch[maxc[cont]]<y) then
      begin mxy:=true; sec:=sec+1; end
     else if (cv[maxc[cont]]<y) and (ch[maxc[cont]]>x) then
       begin xmy:=true; sec:=sec+1; end;
    if (sec>3) or ((xy) and (mxmy)) or ((mxy) and (xmy)) then
      begin
        aumenta:=true;
        mindx[1]:=x;
        mindy[1]:=y; 
        minn:=1;
      end   
    else
      begin
        if (xy) and (mxy) then
          y:=y+1
        else if (xy) and (xmy) then
          x:=x+1
        else if (mxmy) and (mxy) then
          x:=x-1
        else if (mxmy) and (xmy) then
          y:=y-1
        else  if xy then
          y:=y+1
        else if mxy then
          x:=x-1
        else if xmy then
          x:=x+1
        else if mxmy then
          y:=y-1;            
      end;         
  if visita[x,y]=1 then aumenta:=true;
until aumenta;
if minn<>1 then
  for cont:=1 to v do
    for cont2:=1 to h do
      if dist[cont,cont2]= minr then begin minn:=minn+1; mindy[minn]:=cont; mindx[minn]:=cont2; end;
for cont:=1 to minn do 
  writeln(textout,mindx[cont],' ',mindy[cont]);
close(textin);
close(textout);
end.
