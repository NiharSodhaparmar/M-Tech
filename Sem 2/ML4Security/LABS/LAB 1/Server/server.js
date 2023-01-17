const express = require("express");
const app = express();

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.listen(5000, () => {
    console.log(`Server is running at port 5000.`);
});

app.get("/", (req, res) => {
    res.status(200).send("OK Server running.");
})