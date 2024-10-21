botonCompletar = document.getElementById("botonCompletar");

botonCompletar.addEventListener("click", () => {
    let mandarOpinion = "";
    let starVal = document.forms["star-rating-form"]["star-radio"].value;
    if (starVal == -1 || starVal === "") {
        mandarOpinion = "Elegiste 0 Estrellas";
    } else {
        mandarOpinion = "Elegiste " + starVal + " Estrellas"; 
    }
    postData("mandarOpinion", mandarOpinion);
});
