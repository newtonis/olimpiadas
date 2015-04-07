type
  vec = array[0..99998]of integer;
var
  i,e,v,h,c,md,d,mad,j,f : integer;
  v1,v2,v3,v4 : vec;
  arch,arch2 : text;
begin
  assign(arch,'compra.in');
  assign(arch2,'compra.out');
  reset(arch);
  mad := -1;
  rewrite(arch2);
  readln(arch,v,h);
  md := v+h+1;
  readln(arch,c);
  for i := 1 to c do
    readln(arch,v3[i],v4[i]);
  for i := 1 to v do
   for e := 1 to h do
     begin
       mad := -1;
       for f := 1 to c do
        begin
          d := abs(v3[f] - i) + abs(v4[f] - e);
          if d > mad then
            mad := d;
         end;
       if mad < md then
        begin
          j := 1;
          md := mad;
          v1[j] := i;
          v2[j] := e;
        end;
       if mad = md then
        begin
          j := j + 1;
          v1[j] := i;
          v2[j] := e;
         end;
     end;
   for i := 2 to j do
     writeln(arch2,v1[i],' ',v2[i]);
   close(arch);
   close(arch2);
end.  
          
                
       
       
           
     
       
       
