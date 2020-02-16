import cyaron

while True:
    io = cyaron.IO(file_prefix="test")
    io.input_writeln(cyaron.String.random((100,5000)))
    io.input_writeln(cyaron.String.random((100,5000)))
    cyaron.Compare.program("E.exe", input=io, std_program="E.exe")
    print("Test")
