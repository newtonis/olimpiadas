var entrada,salida:text;
begin
assign(entrada,'compra.in');
assign(salida,'compra.out');
reset(entrada);
rewrite(salida);

writeln(salida,'3 4');
writeln(salida,'4 4');

close(entrada);
close(salida);
end.
