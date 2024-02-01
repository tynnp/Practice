program XinChao;

var
    n, i: integer;

begin
    readln(n);

    for i := 1 to n do
    begin
        write('Xin chao!');
        if i <> n then
            writeln('');
    end;
end.