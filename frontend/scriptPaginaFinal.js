botonCompletar = document.getElementById("botonCompletar");

botonCompletar.addEventListener("click", () => {
    textoFeedback = document.getElementById("textoFeedback").value;
    postData("textoFeedback", textoFeedback);
    postData("botonCompletar", botonCompletar);
});

document.addEventListener("DOMContentLoaded", () => {
    displayValue();
    document.forms["star-rating-form"]["star-radio"].forEach((star) => {
    star.addEventListener("change", () => {
        displayValue();
    });
    });
});