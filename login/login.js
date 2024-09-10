let botonG = document.getElementById("botonGuardar");
let botonC = document.getElementById("botonCargar");
let botonB = document.getElementById("botonBorrar");

botonG.addEventListener("click", clickG);

function clickG(){
    let valorN = document.getElementById("valorNombre").value;
    let valorG = document.getElementById("valorGrado").value;
    let valorO = document.getElementById("valorOrientacion").value;
    localStorage.setItem("valorN", valorN);
    localStorage.setItem("valorG", valorG);
    localStorage.setItem("valorO", valorO);
    document.getElementById("valorNombre").value = "";
    document.getElementById("valorGrado").value = "";
    document.getElementById("valorOrientacion").value = "";
}

botonC.addEventListener("click", clickC);

function clickC(){
    let valorN = localStorage.getItem("valorN");
    let valorG = localStorage.getItem("valorG");
    let valorO = localStorage.getItem("valorO");
    document.getElementById("valorMostrar1").innerHTML = "Nombre: " + valorN;
    document.getElementById("valorMostrar2").innerHTML = "Grado: " + valorG;
    document.getElementById("valorMostrar3").innerHTML = "Orientacion: " + valorO;
}

botonB.addEventListener("click", clickB);

function clickB(){
    document.getElementById("valorMostrar1").innerHTML = "";
    localStorage.clear();
    document.getElementById("valorMostrar2").innerHTML = "";
    localStorage.clear();
    document.getElementById("valorMostrar3").innerHTML = "";
    localStorage.clear();
}