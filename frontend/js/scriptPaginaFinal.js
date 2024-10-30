botonCompletar = document.getElementById("botonCompletar");

botonCompletar.addEventListener("click", () => {
    let mandarOpinion = "";
    let starVal = document.querySelector('input[name="star-radio"]:checked');
    if (starVal) {
        mandarOpinion = "Elegiste " + starVal.value + " Estrellas";
    } else {
        mandarOpinion = "Elegiste 0 Estrellas";
    }
    postData("mandarOpinion", mandarOpinion);
    window.location.href = 'index.html';
});
