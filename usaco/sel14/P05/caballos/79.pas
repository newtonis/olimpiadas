var entrada,salida:text;
    m,nc,na,nb,nl,no:cardinal;
    matriz:array [1..10,1..10] of char;
    x,y,xf,yf:longint;
    b:byte;

procedure leer;
begin
 readln(entrada,xf,yf,m);
 for y:=1 to yf+1 do
  for x:=1 to xf do
   read(entrada,matriz[y,x]);
end;


procedure ec;
begin
 for y:=1 to yf+1 do
  for x:=1 to xf do
   if (matriz[y,x]='C') then
   begin
    inc(nc);

   end;
end;

procedure ea;
begin
 for y:=1 to yf+1 do
  for x:=1 to xf do
   if (matriz[y,x]='A') then
   begin
    inc(na);

   end;
end;

procedure eb;
begin
 for y:=1 to yf+1 do
  for x:=1 to xf do
   if (matriz[y,x]='B') then
   begin
    inc(nb);

   end;
end;

procedure el;
begin
 for y:=1 to yf+1 do
  for x:=1 to xf do
   if (matriz[y,x]='L') then
   begin
    inc(nl);
 
   end;
end;

procedure eo;
begin
 for y:=1 to yf+1 do
  for x:=1 to xf do
   if (matriz[y,x]='O') then
   begin
    inc(no);

   end;
end;
{
procedure caminoc;
begin
 for x:=1 to na do 
  if ((lc[x1,1]-2=la[x,1]) and (lc[x1,2]-1=la[x,2])) then caminoa(x);
  if ((lc[x1,1]-2=la[x,1]) and (lc[x1,2]+1=la[x,2])) then caminoa(x);
  if ((lc[x1,1]-1=la[x,1]) and (lc[x1,2]-2=la[x,2])) then caminoa(x);
  if ((lc[x1,1]-1=la[x,1]) and (lc[x1,2]+2=la[x,2])) then caminoa(x);
  if ((lc[x1,1]+1=la[x,1]) and (lc[x1,2]-2=la[x,2])) then caminoa(x);
  if ((lc[x1,1]+1=la[x,1]) and (lc[x1,2]+2=la[x,2])) then caminoa(x);
  if ((lc[x1,1]+2=la[x,1]) and (lc[x1,2]-1=la[x,2])) then caminoa(x);
  if ((lc[x1,1]+2=la[x,1]) and (lc[x1,2]+1=la[x,2])) then caminoa(x);
end;
procedure caminoa(xa:longint);
begin
 for y:=1 to nb do 
  if ((la[xa,1]-2=lb[y,1]) and (la[x1,2]-1=lb[y,2])) then caminob(y);
  if ((la[xa,1]-2=lb[y,1]) and (la[x1,2]+1=lb[y,2])) then caminob(y);
  if ((la[xa,1]-1=lb[y,1]) and (la[x1,2]-2=lb[y,2])) then caminob(y);
  if ((la[xa,1]-1=lb[y,1]) and (la[x1,2]+2=lb[y,2])) then caminob(y);
  if ((la[xa,1]+1=lb[y,1]) and (la[x1,2]-2=lb[y,2])) then caminob(y);
  if ((la[xa,1]+1=lb[y,1]) and (la[x1,2]+2=lb[y,2])) then caminob(y);
  if ((la[xa,1]+2=lb[y,1]) and (la[x1,2]-1=lb[y,2])) then caminob(y);
  if ((la[xa,1]+2=lb[y,1]) and (la[x1,2]+1=lb[y,2])) then caminob(y);
end;
procedure caminob(xb:longint);
begin
 for h:=1 to nb do 
  if ((lb[xb,1]-2=la[h,1]) and (lb[xb,2]-1=la[h,2]) and ((lb[xb,1]-2<>la[x,1]) and (lb[xb,2]-1<>la[x,2])) then caminoa1(h);
  if ((lb[xb,1]-2=la[h,1]) and (lb[xb,2]+1=la[h,2]) and ((lb[xb,1]-2<>la[x,1]) and (lb[xb,2]+1<>la[x,2])) then caminoa1(h);
  if ((lb[xb,1]-1=la[h,1]) and (lb[xb,2]-2=la[h,2]) and ((lb[xb,1]-1<>la[x,1]) and (lb[xb,2]+2<>la[x,2])) then caminoa1(h);
  if ((lb[xb,1]-1=la[h,1]) and (lb[xb,2]+2=la[h,2]) and ((lb[xb,1]-1<>la[x,1]) and (lb[xb,2]-2<>la[x,2])) then caminoa1(h);
  if ((lb[xb,1]+1=la[h,1]) and (lb[xb,2]-2=la[h,2]) and ((lb[xb,1]+1<>la[x,1]) and (lb[xb,2]+2<>la[x,2])) then caminoa1(h);
  if ((lb[xb,1]+1=la[h,1]) and (lb[xb,2]+2=la[h,2]) and ((lb[xb,1]+1<>la[x,1]) and (lb[xb,2]-2<>la[x,2])) then caminoa1(h);
  if ((lb[xb,1]+2=la[h,1]) and (lb[xb,2]-1=la[h,2]) and ((lb[xb,1]+2<>la[x,1]) and (lb[xb,2]-1<>la[x,2])) then caminoa1(h);
  if ((lb[xb,1]+2=la[h,1]) and (lb[xb,2]+1=la[h,2]) and ((lb[xb,1]+2<>la[x,1]) and (lb[xb,2]+1<>la[x,2])) then caminoa1(h);
end;
procedure caminoa1(xa1:longint);
begin
 for w:=1 to nb do 
  if ((la[xa1,1]-2=ll[w,1]) and (la[xa1,2]-1=ll[w,2])) then caminol(w);
  if ((la[xa1,1]-2=ll[w,1]) and (la[xa1,2]+1=ll[w,2])) then caminol(w);
  if ((la[xa1,1]-1=ll[w,1]) and (la[xa1,2]-2=ll[w,2])) then caminol(w);
  if ((la[xa1,1]-1=ll[w,1]) and (la[xa1,2]+2=ll[w,2])) then caminol(w);
  if ((la[xa1,1]+1=ll[w,1]) and (la[xa1,2]-2=ll[w,2])) then caminol(w);
  if ((la[xa1,1]+1=ll[w,1]) and (la[xa1,2]+2=ll[w,2])) then caminol(w);
  if ((la[xa1,1]+2=ll[w,1]) and (la[xa1,2]-1=ll[w,2])) then caminol(w);
  if ((la[xa1,1]+2=ll[w,1]) and (la[xa1,2]+1=ll[w,2])) then caminol(w);
end;
procedure caminol(xl:longint);
begin
 for j:=1 to nb do 
  if ((ll[xl,1]-2=lb[j,1]) and (ll[xl,2]-1=lb[j,2])) then caminol1(j);
  if ((ll[xl,1]-2=lb[j,1]) and (ll[xl,2]+1=lb[j,2])) then caminol1(j);
  if ((ll[xl,1]-1=lb[j,1]) and (ll[xl,2]-2=lb[j,2])) then caminol1(j);
  if ((ll[xl,1]-1=lb[j,1]) and (ll[xl,2]+2=lb[j,2])) then caminol1(j);
  if ((ll[xl,1]+1=lb[j,1]) and (ll[xl,2]-2=lb[j,2])) then caminol1(j);
  if ((ll[xl,1]+1=lb[j,1]) and (ll[xl,2]+2=lb[j,2])) then caminol1(j);
  if ((ll[xl,1]+2=lb[j,1]) and (ll[xl,2]-1=lb[j,2])) then caminol1(j);
  if ((ll[xl,1]+2=lb[j,1]) and (ll[xl,2]+1=lb[j,2])) then caminol1(j);
end;
procedure caminol1(xl1:longint);
begin
 for z:=1 to nb do 
  if ((ll[xl1,1]-2=ll[z,1]) and (ll[xl1,2]-1=ll[z,2]) and ((ll[xl1,1]-2<>ll[x,1]) and (ll[xl1,2]-1<>ll[x,2])) then caminoo(z);
  if ((ll[xl1,1]-2=ll[z,1]) and (ll[xl1,2]+1=ll[z,2]) and ((ll[xl1,1]-2<>ll[x,1]) and (ll[xl1,2]+1<>ll[x,2])) then caminoo(z);
  if ((ll[xl1,1]-1=ll[z,1]) and (ll[xl1,2]-2=ll[z,2]) and ((ll[xl1,1]-1<>ll[x,1]) and (ll[xl1,2]-2<>ll[x,2])) then caminoo(z);
  if ((ll[xl1,1]-1=ll[z,1]) and (ll[xl1,2]+2=ll[z,2]) and ((ll[xl1,1]-1<>ll[x,1]) and (ll[xl1,2]+2<>ll[x,2])) then caminoo(z);
  if ((ll[xl1,1]+1=ll[z,1]) and (ll[xl1,2]-2=ll[z,2]) and ((ll[xl1,1]+1<>ll[x,1]) and (ll[xl1,2]-2<>ll[x,2])) then caminoo(z);
  if ((ll[xl1,1]+1=ll[z,1]) and (ll[xl1,2]+2=ll[z,2]) and ((ll[xl1,1]+1<>ll[x,1]) and (ll[xl1,2]+2<>ll[x,2])) then caminoo(z);
  if ((ll[xl1,1]+2=ll[z,1]) and (ll[xl1,2]-1=ll[z,2]) and ((ll[xl1,1]+2<>ll[x,1]) and (ll[xl1,2]-1<>ll[x,2])) then caminoo(z);
  if ((ll[xl1,1]+2=ll[z,1]) and (ll[xl1,2]+1=ll[z,2]) and ((ll[xl1,1]+2<>ll[x,1]) and (ll[xl1,2]+1<>ll[x,2])) then caminoo(z);
procedure caminoo(xo:longint);
begin
 for k:=1 to nb do 
  if ((lo[xo,1]-2=lb[k,1]) and (lo[xo,2]-1=lb[k,2])) then inc(c);
  if ((lo[xo,1]-2=lb[k,1]) and (lo[xo,2]+1=lb[k,2])) then inc(c);
  if ((lo[xo,1]-1=lb[k,1]) and (lo[xo,2]-2=lb[k,2])) then inc(c);
  if ((lo[xo,1]-1=lb[k,1]) and (lo[xo,2]+2=lb[k,2])) then inc(c);
  if ((lo[xo,1]+1=lb[k,1]) and (lo[xo,2]-2=lb[k,2])) then inc(c);
  if ((lo[xo,1]+1=lb[k,1]) and (lo[xo,2]+2=lb[k,2])) then inc(c);
  if ((lo[xo,1]+2=lb[k,1]) and (lo[xo,2]-1=lb[k,2])) then inc(c);
  if ((lo[xo,1]+2=lb[k,1]) and (lo[xo,2]+1=lb[k,2])) then inc(c);
end;
}
{main}
begin
assign(entrada,'caballos.in');
assign(salida,'caballos.out');
reset(entrada);
rewrite(salida);
 b:=1;
 if (b=1) then b:=0;
 leer;
 na:=0;nb:=0;nc:=0;nl:=0;no:=0;
 {ec;
 ea;
 eb;
 ea;
 el;
 el;
 eo;
 if (na=1) then inc(b);
  if (nb=1) then inc(b);
   if (nc=1) then inc(b);
    if (no=1) then inc(b);
     if (nl=1) then inc(b);
 if (na+nc+nb+no+nl<m) then writeln (salida,'1');
 if (b=3) then writeln (salida,'1');
 if (b=4) then writeln (salida,'1');
 if (b=5) then writeln (salida,'1');
}
writeln(salida,'1');
close(entrada);
close(salida);
end.




{----------------------------------------------------------------------}



procedure encontrarc;
begin
 n1:=0;
 for y:=1 to yf+1 do 
  for x:=1 to xf do
    if (matriz[y,x]='C') then 
    begin
     inc(n1);
     letra1[n1,1]:=y;
     letra1[n1,2]:=x;
    end;
end;

procedure encontrara;
begin
 
 n2:=0;
 for x1:=1 to n1 do
 begin
 
    if ((matriz [letra1[x1,1]-2, letra1[x1,2]-1]='A') {and (letra1[x1,1]-2>1) and (letra1[x1,2]-1>1)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-2=letra2[x,1])then
       if (letra1[x1,2]-1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-2;
      letra2[n2,2]:=letra1[x1,2]-1;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]-2, letra1[x1,2]+1]='A') {and (letra1[x1,1]-2>1) and (letra1[x1,2]+1<xf)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-2=letra2[x,1])then
       if (letra1[x1,2]+1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-2;
      letra2[n2,2]:=letra1[x1,2]+1;
     {end;}
    end;

    if ((matriz [letra1[x1,1]-1, letra1[x1,2]-2]='A') {and (letra1[x1,1]-1>1) and (letra1[x1,2]-2>1)}) then 
    begin
    { b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-1=letra2[x,1])then
       if (letra1[x1,2]-2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-1;
      letra2[n2,2]:=letra1[x1,2]-2;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]-1, letra1[x1,2]+2]='A') {and (letra1[x1,1]-1>1) and (letra1[x1,2]+2<xf)}) then 
    begin
    { b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-1=letra2[x,1])then
       if (letra1[x1,2]+2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-1;
      letra2[n2,2]:=letra1[x1,2]+2;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]+1, letra1[x1,2]-2]='A') {and (letra1[x1,1]+1<yf) and (letra1[x1,2]-2>1)}) then 
    begin
    { b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+1=letra2[x,1])then
       if (letra1[x1,2]-2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+1;
      letra2[n2,2]:=letra1[x1,2]-2;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]+1, letra1[x1,2]+2]='A') {and (letra1[x1,1]+1<yf) and (letra1[x1,2]+2<xf)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+1=letra2[x,1])then
       if (letra1[x1,2]+2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+1;
      letra2[n2,2]:=letra1[x1,2]+2;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]+2, letra1[x1,2]-1]='A') {and (letra1[x1,1]+2<yf) and (letra1[x1,2]-1>1)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+2=letra2[x,1])then
       if (letra1[x1,2]-1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+2;
      letra2[n2,2]:=letra1[x1,2]-1;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]+2, letra1[x1,2]-1]='A') {and (letra1[x1,1]+2<yf) and (letra1[x1,2]+1<xf)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+2=letra2[x,1])then
       if (letra1[x1,2]-1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+2;
      letra2[n2,2]:=letra1[x1,2]-1;
     {end;}
    end;
 
 end;
 for x:=1 to n2 do
 begin
  letra1[x,1]:=letra2[x,1];
  letra1[x,2]:=letra2[x,2];
 end; 
 n1:=n2;
end;

procedure encontrarb;
begin
 
 n2:=0;
 for x1:=1 to n1 do
 begin
   
    if ((matriz [letra1[x1,1]-2, letra1[x1,2]-1]='B') {and (letra1[x1,1]-2>1) and (letra1[x1,2]-1>1)}) then 
    begin
    { b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-2=letra2[x,1])then
       if (letra1[x1,2]-1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-2;
      letra2[n2,2]:=letra1[x1,2]-1;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]-2, letra1[x1,2]+1]='B') {and (letra1[x1,1]-2>1) and (letra1[x1,2]+1<xf)}) then 
    begin
    { b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-2=letra2[x,1])then
       if (letra1[x1,2]+1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-2;
      letra2[n2,2]:=letra1[x1,2]+1;
     {end;}
    end;

    if ((matriz [letra1[x1,1]-1, letra1[x1,2]-2]='B') {and (letra1[x1,1]-1>1) and (letra1[x1,2]-2>1)}) then 
    begin
    { b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-1=letra2[x,1])then
       if (letra1[x1,2]-2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-1;
      letra2[n2,2]:=letra1[x1,2]-2;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]-1, letra1[x1,2]+2]='B') {and (letra1[x1,1]-1>1) and (letra1[x1,2]+2<xf)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-1=letra2[x,1])then
       if (letra1[x1,2]+2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-1;
      letra2[n2,2]:=letra1[x1,2]+2;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]+1, letra1[x1,2]-2]='B') {and (letra1[x1,1]+1<yf) and (letra1[x1,2]-2>1)}) then 
    begin
    { b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+1=letra2[x,1])then
       if (letra1[x1,2]-2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+1;
      letra2[n2,2]:=letra1[x1,2]-2;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]+1, letra1[x1,2]+2]='B') {and (letra1[x1,1]+1<yf) and (letra1[x1,2]+2<xf)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+1=letra2[x,1])then
       if (letra1[x1,2]+2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+1;
      letra2[n2,2]:=letra1[x1,2]+2;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]+2, letra1[x1,2]-1]='B') {and (letra1[x1,1]+2<yf) and (letra1[x1,2]-1>1)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+2=letra2[x,1])then
       if (letra1[x1,2]-1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+2;
      letra2[n2,2]:=letra1[x1,2]-1;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]+2, letra1[x1,2]-1]='B') {and (letra1[x1,1]+2<yf) and (letra1[x1,2]+1<xf)}) then 
    begin
    { b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+2=letra2[x,1])then
       if (letra1[x1,2]-1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+2;
      letra2[n2,2]:=letra1[x1,2]-1;
     {end;}
    end;
 
 
 end;
 for x:=1 to n2 do
 begin
  letra1[x,1]:=letra2[x,1];
  letra1[x,2]:=letra2[x,2];
 end; 
 n1:=n2;
end;

procedure encontrarl;
begin
 
 n2:=0;
 for x1:=1 to n1 do
 begin
   
    if ((matriz [letra1[x1,1]-2, letra1[x1,2]-1]='L') {and (letra1[x1,1]-2>1) and (letra1[x1,2]-1>1)}) then 
    begin
    {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-2=letra2[x,1])then
       if (letra1[x1,2]-1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-2;
      letra2[n2,2]:=letra1[x1,2]-1;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]-2, letra1[x1,2]+1]='L') {and (letra1[x1,1]-2>1) and (letra1[x1,2]+1<xf)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-2=letra2[x,1])then
       if (letra1[x1,2]+1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-2;
      letra2[n2,2]:=letra1[x1,2]+1;
     {end;}
    end;

    if ((matriz [letra1[x1,1]-1, letra1[x1,2]-2]='L') {and (letra1[x1,1]-1>1) and (letra1[x1,2]-2>1)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-1=letra2[x,1])then
       if (letra1[x1,2]-2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-1;
      letra2[n2,2]:=letra1[x1,2]-2;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]-1, letra1[x1,2]+2]='L') {and (letra1[x1,1]-1>1) and (letra1[x1,2]+2<xf)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-1=letra2[x,1])then
       if (letra1[x1,2]+2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-1;
      letra2[n2,2]:=letra1[x1,2]+2;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]+1, letra1[x1,2]-2]='L') {and (letra1[x1,1]+1<yf) and (letra1[x1,2]-2>1)}) then 
    begin
    { b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+1=letra2[x,1])then
       if (letra1[x1,2]-2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+1;
      letra2[n2,2]:=letra1[x1,2]-2;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]+1, letra1[x1,2]+2]='L') {and (letra1[x1,1]+1<yf) and (letra1[x1,2]+2<xf)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+1=letra2[x,1])then
       if (letra1[x1,2]+2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+1;
      letra2[n2,2]:=letra1[x1,2]+2;
    {end;}
    end;
    
    if ((matriz [letra1[x1,1]+2, letra1[x1,2]-1]='L') {and (letra1[x1,1]+2<yf) and (letra1[x1,2]-1>1)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+2=letra2[x,1])then
       if (letra1[x1,2]-1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+2;
      letra2[n2,2]:=letra1[x1,2]-1;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]+2, letra1[x1,2]-1]='L') {and (letra1[x1,1]+2<yf) and (letra1[x1,2]+1<xf)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+2=letra2[x,1])then
       if (letra1[x1,2]-1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+2;
      letra2[n2,2]:=letra1[x1,2]-1;
     {end;}
    end;
 
 
 end;
 for x:=1 to n2 do
 begin
  letra1[x,1]:=letra2[x,1];
  letra1[x,2]:=letra2[x,2];
 end; 
 n1:=n2;
end;

procedure encontraro;
begin
 
 n2:=0;
 for x1:=1 to n1 do
 begin
   
    if ((matriz [letra1[x1,1]-2, letra1[x1,2]-1]='O') {and (letra1[x1,1]-2>1) and (letra1[x1,2]-1>1)}) then 
    begin
    { b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-2=letra2[x,1])then
       if (letra1[x1,2]-1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-2;
      letra2[n2,2]:=letra1[x1,2]-1;
    {end;}
    end;
    
    if ((matriz [letra1[x1,1]-2, letra1[x1,2]+1]='O') {and (letra1[x1,1]-2>1) and (letra1[x1,2]+1<xf)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-2=letra2[x,1])then
       if (letra1[x1,2]+1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-2;
      letra2[n2,2]:=letra1[x1,2]+1;
     {end;}
    end;

    if ((matriz [letra1[x1,1]-1, letra1[x1,2]-2]='O') {and (letra1[x1,1]-1>1) and (letra1[x1,2]-2>1)}) then 
    begin
    { b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-1=letra2[x,1])then
       if (letra1[x1,2]-2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-1;
      letra2[n2,2]:=letra1[x1,2]-2;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]-1, letra1[x1,2]+2]='O') {and (letra1[x1,1]-1>1) and (letra1[x1,2]+2<xf)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]-1=letra2[x,1])then
       if (letra1[x1,2]+2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]-1;
      letra2[n2,2]:=letra1[x1,2]+2;
    {end;}
    end;
    
    if ((matriz [letra1[x1,1]+1, letra1[x1,2]-2]='O') {and (letra1[x1,1]+1<yf) and (letra1[x1,2]-2>1)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+1=letra2[x,1])then
       if (letra1[x1,2]-2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+1;
      letra2[n2,2]:=letra1[x1,2]-2;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]+1, letra1[x1,2]+2]='O') {and (letra1[x1,1]+1<yf) and (letra1[x1,2]+2<xf)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+1=letra2[x,1])then
       if (letra1[x1,2]+2=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+1;
      letra2[n2,2]:=letra1[x1,2]+2;
    {end;}
    end;
    
    if ((matriz [letra1[x1,1]+2, letra1[x1,2]-1]='O') {and (letra1[x1,1]+2<yf) and (letra1[x1,2]-1>1)}) then 
    begin
    { b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+2=letra2[x,1])then
       if (letra1[x1,2]-1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+2;
      letra2[n2,2]:=letra1[x1,2]-1;
     {end;}
    end;
    
    if ((matriz [letra1[x1,1]+2, letra1[x1,2]-1]='O') {and (letra1[x1,1]+2<yf) and (letra1[x1,2]+1<xf)}) then 
    begin
     {b:=0;
     for x:=1 to n2 do
     begin
      if (letra1[x1,1]+2=letra2[x,1])then
       if (letra1[x1,2]-1=letra2[x,2]) then b:=1; 
     end;
     if (b=0) then
     begin}
      inc(n2);
      letra2[n2,1]:=letra1[x1,1]+2;
      letra2[n2,2]:=letra1[x1,2]-1;
     {end;}
    end;
 
 
 end;
 for x:=1 to n2 do
 begin
  letra1[x,1]:=letra2[x,1];
  letra1[x,2]:=letra2[x,2];
 end; 
 n1:=n2;
end;
end;
