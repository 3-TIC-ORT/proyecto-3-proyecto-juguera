const checkBox = document.getElementById("confirmar");
checkBox.addEventListener("click", async()=>{
    checkBox.style.opacity = "70%";
    let Confirmar = "Si";
    postData("Confirmar", Confirmar);
    window.location.href = "pagina4.html";
})