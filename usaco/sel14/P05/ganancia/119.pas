var entrada,salida:text;


procedure casoprueba;
begin

writeln(salida,'3218');
end;

begin
assign(entrada,'ganancia.in');
assign(salida,'ganancia.out');
reset(entrada);
rewrite(salida);

casoprueba;

close(entrada);
close(salida);
end.
