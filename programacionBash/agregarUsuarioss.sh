#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi

file=$1

if [ "${file}X" = "X" ];
then
   echo "++++++ NO se especifico el archivo con el listado de usuarios++++++"
   exit 1
fi

file=$1

if [ "${file}X" = "X" ];
then
   echo "++++++ NO se especifico el archivo con el listado de usuarios++++++"
   exit 1
fi

# Del archivo con el listado de usuarios a ingresar:
# Este es el formato:
# usuario:90-elisabet:575:0:BO-P ELISABET ANTONIO:/home/ejemplo/:/bin/bash
#    |         |       |  |             |               |            | 
#    f1       f2       f3 f4           f5              f6           f7
#$f1 = nUsuario
#$f2 = contra     
#$f3 = ID Usuario 
#$f4 = ID Grupo    
#$f5 = Informacion del ID del Usuario
#$f6 = directorio
#$f7 = comando

creacionUsuario()
{

       #asignamos valores a las variables
	eval nUsuario="$1"
	eval contra="$2"
	eval idUser="$3"
	eval idGp="$4"
	eval infoIDuser="$5"
	eval home="$6"
	eval comando="$7"

	#Verificamos que el usuario no exista, grep verifica o encuentra un texto dentro del archivo que indiquemos, en este caso /etc/passwd
	if grep -i "${nUsuario}" /etc/passwd 
	then
	    echo ">>----El usuario [${username}] ya existe---<<"
	else
         #verificamos que el grupo al que se desea agregar al usuario exista.
         #el parametro -i es para buscar tanto mayusculas y minusculas, en caso de que el nombre del grupo contengan ambos.
	    if grep -i "${idGp}" /etc/group 

     	        useradd "${nUsuario}" "${contra}" "${idUser}" "${idGp}" "${infoIDuser}" "${home}" "${comando}"

		#Asignamos contraseña
	        echo  "$nUsuario:$contra | passwd

		#Al iniciar sesion el usuaro debera cambiar la contraseña al proximo intento de sesion
		#--expire especifica el tiempo que expira la cuenta 
	        passwd --expire "${nUsuario}"

	        if [ $? -eq $SUCCESS ];
	        then
	            echo "---Usuario : [${nUsuario}] agregado de manera exitosa---"
	        fi
	    else
	        echo "xxxxx Grupo [${idGP}] no encontrado. Usuario [${nUsuario}] no agregado xxxxx }"
	    fi
	fi
}

#lectura del fichero linea por linea
while IFS=: read -a line
        encabezado=$(echo "$ {line[0]}" | grep "#")  #salta el encabezado en caso de haber 
      do
        #pasamos a las varianles nombreUsuario, password, userID, groupID, userIDinfo, homeDirectory, comandShell
        nUsuario= "${line[0]}"
        #nUsuario= $(echo "$Usuario //;}")
        contra= "${line[1]}"
        contra#password= $(echo "$Password //;}")
        idUser= "${line[2]}"
        #idUser= $(echo "$ID Usuario //;}")
        idGp= "${line[3]}"
        #idGp= $(echo "$ID grupo //;}")
        infoIDuser= "${line[4]}"
        #infoIDuser= $(echo "$Informacion ID Usuario //;}")
        home= "${line[5]}"
        #homeDirectory= $(echo "$homeDirectory//;}")
        comando= "${line[6]}"
        #comando= $(echo "$Comando Shell//;}")
        
	creacionUsuario "${nUsuario}" "${contra}" "${idUser}" "${idGp}" "${infoIDuser}" "${home}" "${comando}"
done < "$file"
exit 0
	
	

