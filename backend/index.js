import {onEvent, sendEvent, startServer} from "soquetic";
import fs from "fs";

if (fs.existsSync("opcionesElegidas.json")) {
    fs.writeFileSync("opcionesElegidas.json", JSON.stringify([]), "utf-8");
}

let botonCompletar = "";
let listaVacia = [];
let lista = {
    "opcionSabor": "",
    "opcionTamaño": ""
};

botonCompletar.addEventListener("click", click);
function click() {
    if (["sabor1", "sabor2", "sabor3", "sabor4"].includes(opcionesSabor) &&
        ["tamaño1", "tamaño2"].includes(opcionesTamaño)) {

        try {
            listaVacia = JSON.parse(fs.readFileSync("opcionesElegidas.json", "utf-8"));
            switch (opcionesSabor) {
                case "sabor1":
                    lista.opcionSabor = "Manzana";
                    break;
                case "sabor2":
                    lista.opcionSabor = "Naranja";
                    break;
                case "sabor3":
                    lista.opcionSabor = "Limon";
                    break;
                case "sabor4":
                    lista.opcionSabor = "Frutilla";
                    break;
            }

            switch (opcionesTamaño) {
                case "tamaño1":
                    lista.opcionTamaño = "Vaso";
                    break;
                case "tamaño2":
                    lista.opcionTamaño = "Jarra";
                    break;
            }
            listaVacia.push(lista);
            fs.writeFileSync("opcionesElegidas.json", JSON.stringify(listaVacia, null, 2), "utf-8");
            console.log("Opciones guardadas exitosamente");
        } catch (error) {
            console.error("Error al intentar leer o escribir en el archivo JSON", error);
        }
    } else {
        console.error("Por favor selecciona una opción válida de sabor y tamaño, tontin");
    }
}

onEvent("data",()=> {
})
startServer();