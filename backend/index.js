import { onEvent, startServer } from "soquetic";
import fs from "fs";
import {SerialPort} from "serialport";

if (fs.existsSync("opcionesElegidas.json")) {
    fs.writeFileSync("opcionesElegidas.json", JSON.stringify([]), "utf-8");
}

let Sabor = "";
let Tamaño = "";
let Texto = "";

onEvent("opcionesSabor", (opcionesSabor) => {
    Sabor = opcionesSabor;
    console.log("Sabor recibido:", Sabor);
});

onEvent("opcionesTamaño", (opcionesTamaño) => {
    Tamaño = opcionesTamaño;
    console.log("Tamaño recibido:", Tamaño);
});

onEvent("textoFeedback", (textoFeedback) => {
    Texto = textoFeedback;
    console.log("Texto recibido:", Texto);
})

onEvent("botonCompletar", () => {
    console.log("/////////Boton recibido");
    if (Sabor && Tamaño && Texto) {
        let listaVacia = JSON.parse(fs.readFileSync("opcionesElegidas.json", "utf-8"));
        
        const lista = {
            opcionSabor: Sabor,
            opcionTamaño: Tamaño,
            opcionTexto: Texto
        };

        listaVacia.push(lista);
        fs.writeFileSync("opcionesElegidas.json", JSON.stringify(listaVacia, null, 2), "utf-8");
        console.log("///////Opciones guardadas exitosamente");
    } else {
        console.error("///////Por favor selecciona una opción válida de sabor, tamaño y texto.");
    }
});

const port = new SerialPort({
    path: 'COM8',
    baudRate: 9600,
})

port.on("open", ()=>{
    console.log("Puerto Abierto");
})

port.on("data",(data)=>{
    console.log(data.toString())
})

port.write(data+"\n", (err)=>{
    console.error(err);
})

startServer();