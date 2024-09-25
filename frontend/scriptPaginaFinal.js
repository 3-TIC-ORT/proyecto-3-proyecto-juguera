botonCompletar = document.getElementById("botonCompletar");

botonCompletar.addEventListener("click", () => {
    textoFeedback = document.getElementById("textoFeedback").value;
    postData("textoFeedback", textoFeedback);
    postData("botonCompletar", botonCompletar);
});