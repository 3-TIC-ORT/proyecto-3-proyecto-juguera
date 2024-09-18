import { onEvent, startServer } from "soquetic";
import fs from "fs";

if (fs.existsSync("opcionesElegidas.json")) {
    fs.writeFileSync("opcionesElegidas.json", JSON.stringify([]), "utf-8");
}

let Sabor = "";
let Tamaño = "";

onEvent("opcionesSabor", (opcionesSabor) => {
    Sabor = opcionesSabor;
    console.log("Sabor recibido:", Sabor);
});

onEvent("opcionesTamaño", (opcionesTamaño) => {
    Tamaño = opcionesTamaño;
    console.log("Tamaño recibido:", Tamaño);
});

onEvent("botonCompletar", () => {
    console.log("/////////Boton recibido")
    if (Sabor || Tamaño) {
        console.log("//////////Evento de clic recibido");
        
        let listaVacia = [];
        let lista = {
            "opcionSabor": "",
            "opcionTamaño": ""
        };

        try {
            listaVacia = JSON.parse(fs.readFileSync("opcionesElegidas.json", "utf-8"));
            
            switch (Sabor) {
                case "sabor1":
                    lista.opcionSabor = "Manzana";
                    break;
                case "sabor2":
                    lista.opcionSabor = "Naranja";
                    break;
                case "sabor3":
                    lista.opcionSabor = "Limón";
                    break;
                case "sabor4":
                    lista.opcionSabor = "Frutilla";
                    break;
            }

            switch (Tamaño) {
                case "tamaño1":
                    lista.opcionTamaño = "Vaso";
                    break;
                case "tamaño2":
                    lista.opcionTamaño = "Jarra";
                    break;
            }

            listaVacia.push(lista);
            fs.writeFileSync("opcionesElegidas.json", JSON.stringify(listaVacia, null, 2), "utf-8");
            console.log("///////Opciones guardadas exitosamente");
        } catch (error) {
            console.error("///////Error al leer o escribir el archivo JSON", error);
        }
    } else {
        console.error("///////Por favor selecciona una opción válida de sabor y tamaño.");
    }
});

startServer();