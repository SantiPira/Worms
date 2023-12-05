#equipo el bate
echo 'b' >> __client_0_pipe__
#realizo un ataque
echo 'c' >> __client_0_pipe__
echo 'v' >> __client_0_pipe__

#desconecto ambos clientes
sleep 1
echo 'q' >> __client_0_pipe__
sleep 1
echo 'q' >> __client_1_pipe__
