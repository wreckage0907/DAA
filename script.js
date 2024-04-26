const topicNames = [
  "Sorting",
  // "Greedy",
  // "Dynamic Programming",
  // "Divide and Conquer",
  // "Backtracking",
];
function gendiv() {
  const container = document.querySelector(".container");

  topicNames.forEach((name) => {
    const topicDiv = document.createElement("div");
    topicDiv.className = "topic";

    const heading = document.createElement("h2");
    heading.textContent = name;
    topicDiv.appendChild(heading);

    const dropdownBtn = document.createElement("button");
    dropdownBtn.className = "dropdown-btn";
    topicDiv.appendChild(dropdownBtn);

    container.appendChild(topicDiv);
  });
}

function loadfile(path) {
  return fetch(path)
    .then((response) => response.text())
    .catch((error) => console.log(error));
}

function filepath(topic) {
  const map = {
    Sorting: "./SORT/insertion.cpp",
  };
  return map[topic];
}
document.addEventListener("DOMContentLoaded", () => {
  gendiv();
  const dropdownButtons = document.querySelectorAll(".dropdown-btn");
  dropdownButtons.forEach((btn) => {
    btn.addEventListener("click", () => {
      btn.classList.toggle("active");
      const topicDiv = btn.parentElement;
      if (btn.classList.contains("active")) {
        const canvas = document.createElement("canvas");
        canvas.width = 800;
        canvas.height = 400;
        topicDiv.appendChild(canvas);
        topicDiv.style.backgroundColor = "white";

        const editor = ace.edit(canvas);
        editor.setTheme("ace/theme/twilight");
        editor.session.setMode("ace/theme/github");
        editor.setValue("Loading...");
        const path = filepath(topicDiv.querySelector("h2").textContent);
        loadfile(path)
          .then((data) => {
            console.log("File contents:", data);
            try {
              editor.setValue(data);
              console.log("File contents set in Ace Editor");
            } catch (err) {
              console.error("Error setting file contents in Ace Editor:", err);
            }
          })
          .catch((error) => {
            console.error("Error loading file:", error);
          });
      } else {
        const canvas = topicDiv.querySelector("canvas");
        if (canvas) {
          canvas.remove();
        }
        topicDiv.style.backgroundColor = "";
      }
    });
  });
});
