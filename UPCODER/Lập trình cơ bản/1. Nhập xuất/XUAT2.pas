var 
    i, j: integer;
begin
    for i := 1 to 5 do
        begin
            for j := 1 to i do
                    write(j);
            writeln();
        end;
end.