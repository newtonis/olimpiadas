var entrada,salida:text;
    p:string;

procedure casoprueba;
begin
readln(entrada,p);
writeln(salida,'Z:((A(CB))(CD)));
end;

begin
assign(entrada,'topos.in');
assign(salida,'topos.out');
reset(entrada);
rewrite(salida);

casoprueba;

close(entrada);
close(salida);
end;
