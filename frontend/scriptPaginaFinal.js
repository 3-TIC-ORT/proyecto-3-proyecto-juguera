botonCompletar = document.getElementById("botonCompletar");
textoFeedback = document.getElementById("");

botonCompletar.addEventListener("click", () => {
    postData("botonCompletar", botonCompletar, devolverBoton);
});

function devolverBoton(){
    console.log("Hola boton");
}