#mato al primer cliente
echo 'm' >> __client_0_pipe__

sleep 1

#desconecto ambos clientes
echo 'q' >> __client_0_pipe__
echo 'q' >> __client_1_pipe__
