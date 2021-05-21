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
   echo ">>>Debe indicar el archivo del listado con Nombres de los usuarios que se desean Ingresar<<<"
   exit 1
fi
# Del archivo con el listado de usuarios a ingresar:
# Este es el formato:
# usuario:90-elisabet:575:0:BO-P ELISABET ANTONIO:/home/ejemplo/:/bin/bash
#    |         |       |  |             |               |            | 
#    f1       f2       f3 f4           f5              f6           f7
#$f1 = nombreUsuario
#$f2 = pasword     *Por defecto es el nombre del usuario, pero cambia al iniciar la sesion
#$f3 = ID Usuario  *Se puede dejar en blanco
#$f4 = ID Grupo    *Debe existir en etc/group
#$f5 = Informacion del ID del Usuario
#$f6 = home directorio
#$f7 = comando shell

crearUsuario()
{
	echo "----> Usuario <----"
	eval nombreUsuario="$1"
	eval password="$2"
	eval userID="$3"
	eval groupID="$4"
	eval userIDinfo="$5"
	eval homeDirectory="$6"
	eval comandShell="$7"
	echo "---------------------"

#Verificamos que el grupo exista
 if grep -q "$4" /etc/group    #si existe el grupo se añade el usuario
 then
      useradd -mg "${nombreUsuario}" "${password}" "${userID}" "${groupID}" "${userIDinfo}" "${homeDirectory}" "${comandShell}"
      passwd --expire "${nombreUsuario}" 
      echo "---->Usuario [${nombreUsuario}] ha sido agregado correctamente<---"
 else  
       echo "---->Grupo [${groupID}] no existe en /etc/group ----> Usuario [${nombreUsuario}] no agregado..."
 fi
 
 
}
#lectura del fichero linea por linea
while IFS=: read -a line
        encabezado=$(echo "$ {line[0]}" | grep "#")  #salta el encabezado en caso de haber 
      do
        #pasamos a las varianles nombreUsuario, password, userID, groupID, userIDinfo, homeDirectory, comandShell
        usuario= "${line[0]}"
        #usuario= $(echo "$usuario //;}")
        password= "${line[1]}"
        #password= $(echo "$Password //;}")
        userID= "${line[2]}"
        #userID= $(echo "$userID//;}")
        groupID= "${line[3]}"
        #groupID= $(echo "$gruopID //;}")
        userIDinfo= "${line[4]}"
        #userIDinfo= $(echo "$userIDinfo //;}")
        homeDirectory= "${line[5]}"
        #homeDirectory= $(echo "$homeDirectory//;}")
        comandShell= "${line[6]}"
        #comandShell= $(echo "$comandShell//;}")
        
	crearUsuario "${usuario}" "${password}" "${userID}" "${groupID}" "${userIDinfo}" "${homeDirectory}" "${comandShell}"
done < "$file"
exit 0
