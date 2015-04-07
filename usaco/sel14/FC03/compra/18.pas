type
  vec = array[0..99998]of longint;
var
  max,may,mix,miy,i,e,v,h,c,x,y,cmx,cmy,cmax,cmay,md,d,mad,j : longint;
  v1,v2 : vec;
  arch,arch2 : text;
begin
  assign(arch,'compra.in');
  assign(arch2,'compra.out');
  reset(arch);
  rewrite(arch2);
  readln(arch,v,h);
  md := v+h+1;
  mix := v + 1;
  miy := h + 1;
  max := -1;
  may := -1;
  readln(arch,c);
  for i := 1 to c do
   begin
     readln(arch,x,y);
     if x < mix then
      begin
        mix := x;
        cmy := y;
      end;
     if y < miy then
      begin
        miy := y;
        cmx := x;
      end;
     if x > max then
      begin
        max := x;
        cmay := y;
      end;
     if y > may then
      begin
        may := y;
        cmax := x;
      end;
   end;
  for i := 1 to v do
   for e := 1 to h do
     begin
       mad := abs(i - mix) + abs(e - cmy);
       d := abs(i - cmx) + abs(e - miy);
       if d > mad then
         mad := d;
       d := abs(i - max) + abs(e - cmay);
       if d > mad then
         mad := d;
       d := abs(i - cmax) + abs(e - may);
       if d > mad then
         mad := d;
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
   for i := 1 to j do
     writeln(arch2,v1[i],' ',v2[i]);
   close(arch);
   close(arch2);
end.  
          
                
       
       
           
     
       
       
