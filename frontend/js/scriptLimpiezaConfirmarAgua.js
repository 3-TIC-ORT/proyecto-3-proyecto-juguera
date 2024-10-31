const Agua = document.getElementById("agua");
Agua.addEventListener("click", async()=>{
    let confirmadoAgua = "confirmado"
    postData("Agua", confirmadoAgua);
});