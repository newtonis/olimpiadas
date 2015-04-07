program casamiento;
type
  m=array [1..10000,0..10000] of integer;
var
  cont,invitados,enemigos,a,b,rta,cont2,cont3,cont4,anterior,lcadena:longint;
  textin,textout:text;
  encuentra:boolean;
  peleados:m;
begin
  assign(textin,'casamiento.in');
  assign(textout,'casamiento.out');
  reset(textin);
  rewrite(textout);
  
  readln(textin,invitados,enemigos);
  for cont:=1 to invitados do
    for cont2:=0 to invitados do
      peleados[cont,cont2]:=0;
 for cont:=1 to enemigos do
    begin
      readln(textin,a,b);
      peleados[a,b]:=1;
      peleados[b,a]:=1;
      peleados[a,0]:=peleados[a,0]+1;
      peleados[b,0]:=peleados[b,0]+1;
    end;
  rta:=0; 
  cont:=0;
  repeat
      cont:=cont+1;
      if peleados[cont,0]=0 then
        begin
          rta:=rta+1;
          peleados[cont,0]:=9;
        end  
      else
        if peleados[cont,0]=1 then
          begin
              peleados[cont,0]:=9;
              lcadena:=1;
              cont3:=cont;
              anterior:=0;
              repeat
                if lcadena>1 then
                  begin
                    anterior:=cont3;
                    cont3:=cont2;
                  end;  
                encuentra:=false;
            
                for cont2:=1 to invitados do
                  if (peleados[cont3,cont2]=1) and (cont2<>anterior) then
                      begin
                        lcadena:=lcadena+1;
                        encuentra:=true;
                        peleados[cont2,0]:=9;
                        cont4:=cont2;
                      end;
                 cont2:=cont4;     
               until not encuentra;
               if lcadena mod 2 = 1 then lcadena:=lcadena+1;
               rta:=rta+lcadena div 2;               
          end;  
  until cont=invitados;
  
  
  for cont:=1 to invitados do
    if peleados[cont,0]=2 then
      begin
        lcadena:=1;
        anterior:=0;
        cont3:=cont;
        cont2:=cont3;
        peleados[cont,0]:=9;
        repeat
           if lcadena>1 then
              begin
                 anterior:=cont3;
              end;   
                 cont3:=cont2;
                encuentra:=false;
          for cont2:=1 to invitados do
            if (peleados[cont3,cont2]=1) and (cont2<>anterior) and (encuentra=false) then
              begin
                lcadena:=lcadena+1;
                encuentra:=true;
                peleados[cont2,0]:=9;
                cont4:=cont2;
              end;
            cont2:=cont4;  
        until cont2=cont;
        lcadena:=lcadena-1;
        if lcadena mod 2=1 then lcadena:=lcadena-1;
        rta:=rta+lcadena div 2;
      end;

  writeln(textout,rta);
  close(textin);
  close(textout);
end.  
