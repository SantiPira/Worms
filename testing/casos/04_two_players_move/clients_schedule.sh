#muevo el primer cliente durante un segundo hacia la izquierda
echo 'a' >> __client_0_pipe__
sleep 1
echo 's' >> __client_0_pipe__
sleep 1
#intento mover durante un segundo el segundo cliente hacia la izquierda, no lograndolo porque no es el turno
echo 'a' >> __client_1_pipe__
sleep 1
echo 's' >> __client_1_pipe__

#desconecto ambos clientes
echo 'q' >> __client_0_pipe__
echo 'q' >> __client_1_pipe__
