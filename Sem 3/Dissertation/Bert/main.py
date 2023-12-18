import os
import torch
from torch import nn
from torch.utils.data import DataLoader, Dataset
from transformers import BertTokenizer, BertModel, AdamW, get_linear_schedule_with_warmup
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, classification_report
import pandas as pd

from load_data import load_data
from text_classification import TextClassificationDataset
from bert_classifier import BERTClassifier
from train_model import train
from evaluate_model import evaluate


train_comments, train_genders = load_data('./prun_train_dataset.csv')
test_comments, test_genders = load_data('./prun_test_dataset.csv')

# Set up parameters
bert_model_name = 'bert-base-uncased'
num_classes = 2
max_length = 128
batch_size = 16
num_epochs = 4
learning_rate = 2e-5

# Initialize tokenizer, dataset, and data loader
tokenizer = BertTokenizer.from_pretrained(bert_model_name)
train_dataset = TextClassificationDataset(train_comments, train_genders, tokenizer, max_length)
test_dataset = TextClassificationDataset(test_comments, test_genders, tokenizer, max_length)
train_dataloader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
test_dataloader = DataLoader(test_dataset, batch_size=batch_size)

# Set up the device and model
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
model = BERTClassifier(bert_model_name, num_classes).to(device)

# Set up optimizer and learning rate scheduler
optimizer = AdamW(model.parameters(), lr=learning_rate)
total_steps = len(train_dataloader) * num_epochs
scheduler = get_linear_schedule_with_warmup(optimizer, num_warmup_steps=0, num_training_steps=total_steps)

# Training the model
for epoch in range(num_epochs):
    print(f"Epoch {epoch + 1}/{num_epochs}")
    train(model, train_dataloader, optimizer, scheduler, device)
    accuracy, report = evaluate(model, test_dataloader, device)
    print(f"Validation Accuracy: {accuracy:.4f}")
    print(report)

# Saving the final model
torch.save(model.state_dict(), "bert_classifier.pth")
