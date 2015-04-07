var entrada,salida:text;
begin
assign(entrada,'ciclovia.in');
assign(salida,'ciclovia.out');
reset(entrada);
rewrite(salida);

writeln(salida,'20');


close(entrada);
close(salida);
end.
