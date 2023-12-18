import pandas as pd

def load_data(data_file):

    # read csv file
    df = pd.read_csv(data_file)
    
    # remove Unnamed: 0 column
    df_columns=df.columns.tolist()
    if "Unnamed: 0" in df_columns:
        df=df.drop(['Unnamed: 0'], axis=1)    
    
    # replace nan(no value) comment with ""(empty string)
    df.fillna("", inplace=True)
    
    allComments = []
    allLabels = []

    for i in range(df.shape[0]):
        fullComment = df["comment"][i]

        if fullComment != "":
            comments = [x.strip() for x in fullComment.split(".")]
            for comment in comments:
                if(comment != ""):
                    allComments.append(comment)
                    allLabels.append(df["user_gender"][i])

    # df = pd.DataFrame(list(zip(allComments, allLabels)), columns=['Comment', 'Gender'])

    labels = [1 if gender == "Male" else 0 for gender in allLabels]

    return allComments, labels