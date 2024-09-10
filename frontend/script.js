let opcionesSabor = "";
let opcionesTamaño = "";
let botonCompletar = document.getElementById("botonCompletar").value;

for (let i = 1; i <= 4; i++) {
    const element = document.getElementById(`sabor${i}`); 
    if (element && element.checked) {
        opcionesSabor = element.value;
        break; 
    }
}

for (let i = 1; i <= 2; i++) {
    const element = document.getElementById(`tamaño${i}`);
    if (element && element.checked) {
        opcionesTamaño = element.value;
        break; 
    }
}

postData("opcionesSabor", opcionesSabor);
postData("opcionesTamaño", opcionesTamaño);
postData("botonCompletar", botonCompletar);