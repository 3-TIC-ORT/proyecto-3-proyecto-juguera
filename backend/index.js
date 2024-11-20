import { onEvent, startServer } from "soquetic";
import fs from "fs";
import {SerialPort, ReadlineParser} from "serialport";

if (fs.existsSync("opcionesElegidas.json")) {
    fs.writeFileSync("opcionesElegidas.json", JSON.stringify([]), "utf-8");
}

const port = new SerialPort({
    path: 'COM3',
    baudRate: 9600
});

const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));

port.on("open", ()=>{
    console.log("Puerto Abierto");
})

let Sabor = "";
let Tamaño = "";
let Estrellas = "";
let Confirmado = false;

function guardarDatos(datos) {
    let listaVacia = JSON.parse(fs.readFileSync("opcionesElegidas.json", "utf-8"));
    listaVacia.push(datos);
    fs.writeFileSync("opcionesElegidas.json", JSON.stringify(listaVacia, null, 2), "utf-8");
}

onEvent("opcionesSabor", (opcionesSabor) => {
    Sabor = opcionesSabor;
    console.log("Sabor recibido:", Sabor);
});

onEvent("opcionesTamaño", (opcionesTamaño) => {
    Tamaño = opcionesTamaño;
    console.log("Tamaño recibido:", Tamaño);
    if (Sabor && Tamaño){
        const lista = { "opcionSabor": Sabor, "opcionTamaño": Tamaño };
        guardarDatos(lista);
        const datosSerial = `${Sabor} ${Tamaño}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
        });
    } else {
        console.error("No funco");
    }
});

onEvent("Confirmar", (Confirmar) => {
    if (!Confirmado){
        console.log(Tamaño, "confirmado?", Confirmar);
        const lista = { "Confirmacion": Tamaño + "? " + Confirmar };
        guardarDatos(lista);
        Confirmado = true;
        const datosSerial = `confirmado\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
        });
        Confirmado = false;
    } else {
        console.log("Ya fue confirmado");
    }
});

onEvent("mandarOpinion", (mandarOpinion) => {
    if (mandarOpinion){
        Estrellas = mandarOpinion;
        console.log("Opinión recibida:", Estrellas);
        const lista = { "Estrellas": Estrellas };
        guardarDatos(lista); 
    }
    else{
        console.log("No funco las estrellas")
    }
});

onEvent("EmpezarLimpieza", (limpieza) => {
    if (limpieza){
        console.log("Proceso de Limpieza activado");
        const datosSerial = `${limpieza}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
        });
    }
});

onEvent("Recipiente", (confirmadoRecipiente) => {
    if (confirmadoRecipiente){
        console.log("Recipiente colocado");
        const datosSerial = `${confirmadoRecipiente}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
        });
    }
});

onEvent("Agua", (confirmadoAgua) => {
    if (confirmadoAgua){
        console.log("Agua colocada");
        const datosSerial = `${confirmadoAgua}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
        });
    }
});

onEvent("EmpezarRecarga", (Recarga) => {
    if (Recarga){
        console.log("Proceso de Recarga activado");
        const datosSerial = `${Recarga}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
        });
    }
});

onEvent("vasoConcentrado", (colocarVaso) => {
    if (colocarVaso){
        console.log("Vaso para el concentrado Confirmado");
        const datosSerial = `${colocarVaso}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
        });
    }
});

onEvent("vasoConcentrado", (colocarPolvo) => {
    if (colocarPolvo){
        console.log("Polvo Confirmado");
        const datosSerial = `${colocarPolvo}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
        });
    }
});

onEvent("recipienteRevolver", (RecipienteRevolver) => {
    if (RecipienteRevolver){
        console.log("Polvo Confirmado");
        const datosSerial = `${RecipienteRevolver}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
        });
    }
});

onEvent("RecargaFinal", (RecargaFinal) => {
    if (RecargaFinal){
        console.log("Polvo Confirmado");
        const datosSerial = `${RecargaFinal}\n`;
        port.write(datosSerial);
        console.log('Datos enviados al Arduino:', datosSerial);
        parser.once('data', (response) => {
            console.log('Respuesta del Arduino:', response.toString());
        });
    }
});

startServer();